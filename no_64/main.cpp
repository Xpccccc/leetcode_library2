
// https://leetcode.cn/problems/minimum-path-sum/
// 64. 最小路径和

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 创建dp表
        // dp[i][j] -- 从起点到当前位置的最小路径和
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 初始化
        dp[0][1] = dp[1][0] = 0;
        // 填表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        // 返回值
        return dp[m][n];
    }
};