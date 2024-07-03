
// https://leetcode.cn/problems/hamming-distance/
// 461. 汉明距离

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        for (int i = 0; i <= 31; ++i) {
            if (((x >> i) & 1) != (1 & (y >> i)))
                ++ret;
        }
        return ret;
    }
};