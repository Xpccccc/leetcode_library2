//
// https://leetcode.cn/problems/matrix-block-sum/
// 1314. 矩阵区域和

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // 二维前缀和
        int n = mat.size(), m = mat[0].size();
        // 初始化dp表
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                           mat[i - 1][j - 1]; // 注意mat是[0,0]开始
            }
        }
        vector<vector<int>> ret(n, vector<int>(m)); // 这也是[0,0]开始
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x1 = max(0, i - k) + 1,
                    y1 = max(0, j - k) + 1; // 左上角坐标
                int x2 = min(n - 1, i + k) + 1,
                    y2 = min(m - 1, j + k) + 1; // 右下角坐标
                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] +
                            dp[x1 - 1][y1 - 1];
            }
        }
        return ret;
    }
};