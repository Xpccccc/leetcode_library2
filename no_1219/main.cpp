
// https://leetcode.cn/problems/path-with-maximum-gold/
// 1219. 黄金矿工

class Solution {
    bool vis[16][16];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int ret;

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    vis[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    vis[i][j] = false;
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int path) {
        ret = max(ret, path);

        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + i, y = dy[k] + j;
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y]) {
                vis[x][y] = true;
                dfs(grid, x, y, path + grid[x][y]);
                vis[x][y] = false;
            }
        }
    }
};