
// https://leetcode.cn/problems/unique-paths-ii/
// 63. 不同路径 II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 1.创建dp表
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 2.初始化
        dp[0][1] = 1;
        // 3.状态转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!obstacleGrid[i - 1][j - 1]) // 当前位置没有障碍物
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 4.返回
        return dp[m][n];
    }
};