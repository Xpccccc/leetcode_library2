
// https://leetcode.cn/problems/is-unique-lcci/
// 面试题 01.01. 判定字符是否唯一

class Solution {
public:
    bool isUnique(string astr) {
        // 位图
        int bitmap = 0;
        for (auto ch : astr) {
            int cur = ch - 'a';
            if ((bitmap >> cur) & 1 == 1)
                return false;
            bitmap |= 1 << cur;
        }
        return true;
    }
};