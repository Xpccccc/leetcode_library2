
// https://leetcode.cn/problems/maximum-sum-circular-subarray/
// 918. 环形子数组的最大和

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 转化为求最大子数组和 和 最小子数组和 ，取最大值
        int n = nums.size();
        // f[i] -- 以i为结尾的最大子数组和
        // g[i] -- 以i为结尾的最小子数组和
        vector<int> f(n + 1), g(n + 1); // 多开一个
        int fmax = -0x3f3f3f3f, gmin = 0x3f3f3f3f;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i - 1];
            f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]); // f[0] == nums[0];
            fmax = max(fmax, f[i]);
            g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]); // g[0] == nums[0];
            gmin = min(gmin, g[i]);
        }
        if (gmin == sum) // 全是负数
            return fmax;
        else
            return max(fmax, sum - gmin);
    }
};