
// https://leetcode.cn/problems/surrounded-regions/
// 130. 被围绕的区域

class Solution {
    int m, n;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

public:
    void solve(vector<vector<char>>& board) {
        // 先处理边界，因为边界不是结果
        m = board.size(), n = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                dfs(board, x, y);
            }
        }
    }
};