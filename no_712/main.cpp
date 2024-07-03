
// https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
// 712. 两个字符串的最小ASCII删除和

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // 转化：两个字符串的最大ASCII和的公共子序列 -- 留下来的字符串ASCII和
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int sum = 0;
        for (auto c : s1)
            sum += (int)c;
        for (auto c : s2)
            sum += (int)c ;
        s1 = " " + s1;
        s2 = " " + s2;
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i - 1][j - 1] + (int)s1[i];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 因为求最大值，所以包含dp[i-1][j-1]的情况
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return sum - 2 * ret;
    }
};