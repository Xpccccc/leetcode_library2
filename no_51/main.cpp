
// https://leetcode.cn/problems/n-queens/
// 51. N 皇后

class Solution {
    bool checkcol[10], checkdig1[20], checkdig2[20];
    vector<string> path;
    vector<vector<string>> ret;

public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n);
        for (int i = 0; i < n; ++i) {
            path[i].append(n, '.');
        }
        dfs(0, n);
        return ret;
    }

    void dfs(int row, int n) {
        if (row == n) {
            ret.push_back(path);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!checkcol[col] && !checkdig1[row - col + n] &&
                !checkdig2[row + col]) {
                path[row][col] = 'Q';
                checkcol[col] = checkdig1[row - col + n] =
                    checkdig2[row + col] = true;
                dfs(row + 1, n);
                path[row][col] = '.';
                checkcol[col] = checkdig1[row - col + n] =
                    checkdig2[row + col] = false;
            }
        }
    }
};