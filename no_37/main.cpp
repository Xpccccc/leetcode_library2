
// 37. 解数独
// https://leetcode.cn/problems/sudoku-solver/

class Solution {
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board);
    }

    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    // 填值
                    for (int num = 1; num <= 9; ++num) {
                        if (!row[i][num] && !col[j][num] &&
                            !grid[i / 3][j / 3][num]) {
                            board[i][j] = num + '0';
                            row[i][num] = col[j][num] =
                                grid[i / 3][j / 3][num] = true;
                            if (dfs(board) == true)
                                return true;
                            // 恢复现场
                            board[i][j] = '.';
                            row[i][num] = col[j][num] =
                                grid[i / 3][j / 3][num] = false;
                        }
                    }
                    return false;// 1-9都不满足
                }
            }
        }
        return true;
    }
};