//
// https://leetcode.cn/problems/product-of-array-except-self/
// 238. 除自身以外数组的乘积

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // 使用前缀积和后缀积
        int n = nums.size();
        // 处理前缀积
        vector<int> f(n);
        f[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * nums[i];
        }
        // 处理后缀积
        vector<int> g(n);
        g[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            g[i] = g[i + 1] * nums[i];
        }
        vector<int> ret(n);
        // 处理边界
        ret[0] = g[1];
        ret[n - 1] = f[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            ret[i] = f[i - 1] * g[i + 1];
        }
        return ret;
    }
};