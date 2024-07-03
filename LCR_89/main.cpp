
// https://leetcode.cn/problems/Gu0c2T/
// LCR 089. 打家劫舍

class Solution {
public:
    int rob(vector<int>& nums) {
        // 创建dp表
        // dp[i] -- 从起始位置到当前位置的最大金额
        // f[i]  -- 当前位置偷，那么上一个位置一定不偷
        // g[i] -- 当前位置不偷，那么上一个位置可以偷或不偷
        int n = nums.size();
        vector<int> f(n), g(n);
        // 初始化
        f[0] = nums[0];
        // 填表
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 返回值
        return max(f[n - 1], g[n - 1]);
    }
};