
// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// 1576. 替换所有的问号

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if ((i == 0 || s[i - 1] != ch) &&
                        (i == n - 1 || s[i + 1] != ch)) {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};