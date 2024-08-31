
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
// 17. 电话号码的字母组合

class Solution {
    vector<string> ret;
    string path;

public:
    vector<string> hash = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ret;
        dfs(digits, 0);
        return ret;
    }

    void dfs(string& digits, int pos) {
        if (pos == digits.size()) {
            ret.push_back(path);
            return;
        }
        for (auto ch : hash[digits[pos] - '0']) {
            path.push_back(ch);
            dfs(digits, pos + 1);
            path.pop_back(); // 恢复现场
        }
    }
};