
// 191. 位1的个数
// 题目链接https://leetcode.cn/problems/number-of-1-bits/

class Solution {
        public:
        int hammingWeight(int n) {
            int ret = 0;
            for (int i = 0; i <= 31; ++i) {
                if ((n >> i) & 1 == 1)
                    ++ret;
            }
            return ret;
        }
};

//int hammingWeight(uint32_t n) {
//    int count = 0;
//    for (int i = 0; i < 32; i++) {
//        if (1 == ((n >> i) & 1))
//            count++;
//    }
//    return count;
//}