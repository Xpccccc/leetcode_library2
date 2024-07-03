
// https://leetcode.cn/problems/combination-sum-iv/
// 377. 组合总和 Ⅳ

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] -- 从前i个位置中凑出和为i的排列数
        int n = nums.size();
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j){
                if (i >= nums[j]) // 确定了最后一个元素为nums[j]，那么只需要看前面有多少种方法组成i - nums[j]，且一个nums[j]就是一种情况
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};