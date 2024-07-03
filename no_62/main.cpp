
// https://leetcode.cn/problems/unique-paths/
// 62. 不同路径

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 多开一行一列
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        // 第一行和第一列初始化为1
        for (int i = 0; i <= n; ++i)
            dp[0][i] = 1;
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};