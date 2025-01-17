
// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
// 329. 矩阵中的最长递增路径

class Solution {
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int memo[201][201];

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = max(ret, dfs(matrix, i, j));
            }
        }

        return ret;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        int ret = 1;
        if (memo[i][j])
            return memo[i][j];
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n &&
                matrix[x][y] > matrix[i][j]) {
                ret = max(ret, dfs(matrix, x, y) + 1);
            }
        }
        memo[i][j] = ret;
        return ret;
    }
};