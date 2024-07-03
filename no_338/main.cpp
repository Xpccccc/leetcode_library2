
// https://leetcode.cn/problems/counting-bits/
// 338. 比特位计数

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            for (int j = 0; j <= 31; ++j) {
                if (1 == (1 & (i >> j)))
                    count++;
            }
            ret[i] = count;
        }
        return ret;
    }
};