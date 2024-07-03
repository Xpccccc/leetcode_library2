
// https://leetcode.cn/problems/maximum-product-subarray/
// 152. 乘积最大子数组

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // f[i] -- 以i为结尾的最大子数组积
        // g[i] -- 以i为结尾的最小子数组积
        int n = nums.size();
        vector<double> f(n + 1), g(n + 1);
        double fmax = -0x3f3f3f3f;
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; ++i) {
            double x = nums[i - 1];
            if (x > 0) {
                f[i] = max(f[i - 1] * x, x); // f[1] = g[1] = nums[0];
                g[i] = min(g[i - 1] * x, x);
            } else {
                f[i] = max(g[i - 1] * x, x);
                g[i] = min(f[i - 1] * x, x);
            }
            fmax = max(fmax, f[i]);
        }

        return fmax;
    }
};