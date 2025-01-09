
// https://leetcode.cn/problems/number-of-islands/
// 200. 岛屿数量

class Solution {
    int m, n;
    bool vis[301][301];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = dy[k] + j;
            if (x < m && x >= 0 && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] == '1') {
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }
};