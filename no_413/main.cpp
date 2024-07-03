
// https://leetcode.cn/problems/arithmetic-slices/
// 413. 等差数列划分

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i] -- 以i为结尾的等差数组的子数组个数
        int n = nums.size();
        vector<int> dp(n);
        int sum = 0;
        for (int i = 2; i < n; ++i) {
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]
                    ? dp[i - 1] + 1
                    : 0;
            sum += dp[i]; // 为什么要全部加起来，因为dp[i]只是以i为结尾的等差数组的子数组个数 ，我们需要的是所有的[i-1,i-2,i-3...]
        }

        return sum;
    }
};