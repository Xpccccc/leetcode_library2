
// https://leetcode.cn/problems/powx-n/
// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / pow(x, -(long long)n) : pow(x, n);
    }

    double pow(double x, long long n) {
        if (n == 0)
            return 1.0;
        auto tmp = pow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : x * tmp * tmp;
    }
};