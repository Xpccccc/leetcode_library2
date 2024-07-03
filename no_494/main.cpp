
// https://leetcode.cn/problems/target-sum/
// 494. 目标和

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 转化：从数组中选一些数，让这些数的和等于a，一共有多少种选法
        // a -- 正数和，b -- 负数和
        // a + b = target , a - b = sum
        // a = (target + sum) / 2

        // dp[i][j] -- 从前i个数中选，所有选法中能凑成和为j的个数
        int n = nums.size();
        int sum = 0;
        for (auto e : nums)
            sum += e;
        int a = (sum + target) / 2;

        if ((sum + target) % 2 || a < 0)
            return 0;
        vector<int> dp(a + 1); // 优化
        dp[0] = 1; // 这里不能一列求，因为nums元素可能是0，得依靠上一行数据
        for (int i = 1; i <= n; ++i) {
            for (int j = a; j >= nums[i - 1]; --j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[a];
    }
};

// class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        // 转化：从数组中选一些数，让这些数的和等于a，一共有多少种选法
//        // a -- 正数和，b -- 负数和
//        // a + b = target , a - b = sum
//        // a = (target + sum) / 2
//
//        // dp[i][j] -- 从前i个数中选，所有选法中能凑成和为j的个数
//        int n = nums.size();
//        int sum = 0;
//        for (auto e : nums)
//            sum += e;
//        int a = (sum + target) / 2;
//
//        if ((sum + target) % 2 || a < 0)
//            return 0;
//        vector<vector<int>> dp(n + 1, vector<int>(a + 1));
//        dp[0][0] = 1; // 这里不能一列求，因为nums元素可能是0，得依靠上一行数据
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 0; j <= a; ++j) { // 这里可以从0开始，j >= nums[i - 1]会保证j等于0的时候，nums[i-1] 为 0
//                dp[i][j] = dp[i - 1][j];
//                if (j >= nums[i - 1])
//                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
//            }
//        }
//        return dp[n][a];
//    }
//};