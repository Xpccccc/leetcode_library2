
// 36. 有效的数独
// https://leetcode.cn/problems/valid-sudoku/

class Solution {
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = grid[i / 3][j / 3][num] =
                            true;
                }
            }
        }
        return true;
    }
};