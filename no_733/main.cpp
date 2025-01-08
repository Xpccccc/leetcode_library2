
// https://leetcode.cn/problems/flood-fill/
// 733. 图像渲染

class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int prev;

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (color == image[sr][sc])
            return image;
        m = image.size(), n = image[0].size();
        prev = image[sr][sc];
        dfs(image, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int color) {
        image[i][j] = color;

        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + i, y = dy[k] + j;
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev) {
                dfs(image, x, y, color);
            }
        }
    }
};