
// https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// LCR 130. 衣橱整理

class Solution {
    int m, n, cnt;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, 1, 0, 0};
    bool vis[101][101];
    int ret;

public:
    int wardrobeFinishing(int _m, int _n, int _cnt) {
        m = _m, n = _n, cnt = _cnt;
        dfs(0, 0);
        return ret;
    }

    void dfs(int i, int j) {
        ++ret;
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                digit(x, y)) {
                dfs(x, y);
            }
        }
    }

    bool digit(int x, int y) {
        int tmp = 0;
        while (x) {
            tmp += x % 10;
            x /= 10;
        }
        while (y) {
            tmp += y % 10;
            y /= 10;
        }
        return tmp <= cnt;
    }
};