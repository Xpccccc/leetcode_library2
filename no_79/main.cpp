
// https://leetcode.cn/problems/word-search/
// 79. 单词搜索

class Solution {
    bool visit[7][7];
    int m, n;

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    if (dfs(board, i, j, word, 1))
                        return true; // 如果找到word第一个和从第二个字符后面的所有字符
                    // 没找到，继续尝试
                    visit[i][j] = false;
                }
            }
        }
        return false; // 没有方案
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos) {
        if (pos == word.size())
            return true;
        for (int k = 0; k < 4; ++k) {
            // 遍历上下左右
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y] &&
                board[x][y] == word[pos]) {
                visit[x][y] = true;
                if (dfs(board, x, y, word, pos + 1))
                    return true;
                visit[x][y] = false; // 恢复现场
            }
        }
        return false;
    }
};