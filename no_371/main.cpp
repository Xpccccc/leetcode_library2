
// https://leetcode.cn/problems/sum-of-two-integers/
// 371. 两整数之和

class Solution {
public:
    int getSum(int a, int b) {

        while (b) {
            // 无进位相加结果
            int x = a ^ b;
            // 进位
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = x;
            b = carry;
        }
        return a;
    }
};