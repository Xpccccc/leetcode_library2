//
// https://leetcode.cn/problems/three-steps-problem-lcci/
// 面试题 08.01. 三步问题

class Solution {
public:
    int waysToStep(int n) {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 4;
        int a = 1;
        int b = 2;
        int c = 4;
        int d = 0;
        const int MOD = 1e9 + 7;
        for (int i = 4; i <= n; ++i) {
            d = ((a + b) % MOD + c) % MOD;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
