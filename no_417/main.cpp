
// https://leetcode.cn/problems/pacific-atlantic-water-flow/
// 417. 太平洋大西洋水流问题

class Solution {
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 正难则反
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> atl(m, vector<bool>(n));
        vector<vector<int>> ret;
        // 先处理太平洋
        for (int i = 0; i < n; ++i) {
            dfs(heights, 0, i, pac);
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, j, 0, pac);
        }

        // 处理大西洋
        for (int i = 0; i < m; ++i) {
            dfs(heights, i, n - 1, atl);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, m - 1, j, atl);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& vis) {
        vis[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                (heights[x][y] >= heights[i][j]))
                dfs(heights, x, y, vis);
        }
    }
};