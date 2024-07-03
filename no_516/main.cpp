
// https://leetcode.cn/problems/longest-palindromic-subsequence/
// 516. 最长回文子序列

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j] -- 在[i,j]区间的最长回文子串序列
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 从上往下，从右往左
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i == j)
                        dp[i][j] = 1;
                    else if (i + 1 == j)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};