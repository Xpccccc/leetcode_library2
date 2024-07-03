
// https://leetcode.cn/problems/partition-equal-subset-sum/
// 416. 分割等和子集

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp[i][j] -- 从前i个数中选，所有选法中能否存在能凑成和为j
        int n = nums.size();
        int sum = 0;
        for (auto e : nums)
            sum += e;
        if (sum % 2)
            return false;
        // 优化空间
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = sum; j >= nums[i - 1]; --j) {
                dp[j] = dp[j - nums[i - 1]] || dp[j];
            }
        }
        return dp[sum / 2];
    }
};