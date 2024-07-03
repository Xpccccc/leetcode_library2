
// https://leetcode.cn/problems/dungeon-game/
// 174. 地下城游戏

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // 创建dp表
        // dp[i][j]  -- 从当前位置走到右下角的最小健康点数
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 初始化
        dp[m][n - 1] = dp[m - 1][n] = 1;
        // 填表 -- 从下往上，从右往左
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // dp[i][j]是从当前位置走到右下角的最小健康点数
                // 那么当前位置血量加上dp[i][j]得大于等于下一个位置的最小健康点数
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j],1);// 防止dp[i][j]为0或者负数
            }
        }
        // 返回结果
        return dp[0][0];
    }
};