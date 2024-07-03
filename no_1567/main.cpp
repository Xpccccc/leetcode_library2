
// https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/
// 1567. 乘积为正数的最长子数组长度

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // f[i] -- 以i为结尾，乘积为正数的最长子数组长度
        // g[i] -- 以i为结尾，乘积为负数的最长子数组长度
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1); // 多开一个
        int maxlen = 0;
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] > 0) {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] == 0 ? 0 : (g[i - 1] + 1);
            } else if (nums[i - 1] < 0) {
                f[i] = g[i - 1] == 0 ? 0 : (g[i - 1] + 1);
                g[i] = f[i - 1] + 1;
            }
            // 等于0不处理
            maxlen = max(maxlen, f[i]);
        }
        return maxlen;
    }
};