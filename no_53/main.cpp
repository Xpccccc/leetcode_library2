
// https://leetcode.cn/problems/maximum-subarray/
// 53. 最大子数组和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] -- 以i为结尾的最大和的连续子数组
        // 1个元素 -- i位置就是当前子数组最大
        // 大于1个元素 -- 包含i位置再加上以i-1为结尾的最大和的连续子数组
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        int maxele = -0x3f3f3f3f;
        for (auto e : dp)
            maxele = max(maxele, e);
        return maxele;
    }
};