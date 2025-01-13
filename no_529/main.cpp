
// https://leetcode.cn/problems/minesweeper/
// 529. 扫雷游戏

class Solution {
    int m, n;
    int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') { // 直接点击到地雷
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        // 统计周围地雷个数
        for (int k = 0; k < 8; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M')
                ++count;
        }

        // 周围有地雷
        if (count) {
            board[i][j] = count + '0';
            return;
        } else { // 没有地雷
            board[i][j] = 'B';
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
                    dfs(board, x, y);
            }
        }
    }
};