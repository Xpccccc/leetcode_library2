
// https://leetcode.cn/problems/letter-case-permutation/
// 784. 字母大小写全排列

class Solution {
    vector<string> ret;
    string path;

public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }

    void dfs(string& s, int pos) {
        if (pos == s.size()) {
            ret.push_back(path);
            return;
        }

        char ch = s[pos];
        path.push_back(ch);
        // 不改变
        dfs(s, pos + 1);
        path.pop_back();

        // 改变
        if (ch < '0' || ch > '9') {
            path.push_back(change(ch));
            dfs(s, pos + 1);
            path.pop_back();
        }
    }

    char change(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;
        } else {
            return ch - 32;
        }
    }
};