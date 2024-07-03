
// https://leetcode.cn/problems/longest-common-subsequence/
// 1143. 最长公共子序列

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] -- t1[0,i],t2[0,j]的最长公共子序列
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};