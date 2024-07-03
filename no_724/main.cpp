
// https://leetcode.cn/problems/find-pivot-index/
// 724. 寻找数组的中心下标

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        // 先求出所有的下标位置的从左端到该位置的和
        int n = nums.size();
        vector<long long> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            if (dp[i - 1] == dp[n] - dp[i])
                return i - 1;
        }
        return -1;
    }
};