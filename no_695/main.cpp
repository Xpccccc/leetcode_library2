

// https://leetcode.cn/problems/max-area-of-island/
// 695. 岛屿的最大面积

class Solution {
    int m, n;
    bool vis[51][51];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int count = 0;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, i, j);
                    ret = max(ret, count);
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        ++count;
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = dy[k] + j;
            if (x < m && x >= 0 && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] == 1) {
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }
};