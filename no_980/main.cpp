
// https://leetcode.cn/problems/unique-paths-iii/
// 980. 不同路径 III

class Solution {
    int m, n;
    bool vis[21][21];
    int ret;
    int step = 2;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int bx = 0, by = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++step;
                }
                if (grid[i][j] == 1) {
                    bx = i;
                    by = j;
                }
            }
        }

        vis[bx][by] = true;
        dfs(grid, bx, by, 1);

        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int cnt) {
        if (grid[i][j] == 2) {
            if (step  == cnt) {
                ret++;
            }
            return;
        }

        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + i, y = dy[k] + j;
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] != -1) {
                vis[x][y] = true;
                dfs(grid, x, y, cnt + 1);
                vis[x][y] = false;
            }
        }
    }
};