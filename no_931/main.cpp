
// https://leetcode.cn/problems/minimum-falling-path-sum/
// 931. 下降路径最小和

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // 创建dp表
        // 多加2列1行 --  防止越界
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2));
        // 初始化
        // 第一行初始化为0
        for (int i = 1; i <= n - 1; ++i) {
            dp[i][0] = dp[i][n + 1] = INT_MAX; // 两边的列初始化为最大值
        }

        // 填表
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] =
                    min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) +
                    matrix[i - 1][j - 1];
            }
        }

        // 返回值
        // 最后一行的最小值
        int ret = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            cout << dp[n][i] << " ";
            ret = min(ret, dp[n][i]);
        }
        return ret;
    }
};