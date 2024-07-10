
// https://leetcode.cn/problems/count-and-say/
// 38. 外观数列

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        if (n == 1)
            return ret;
        // n-1次
        for (int i = 1; i < n; ++i) {
            string tmp;
            int left = 0, right = 0;
            while (right < ret.size()) {
                while (right < ret.size() && ret[left] == ret[right]) {
                    ++right;
                }
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};