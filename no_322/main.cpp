
// https://leetcode.cn/problems/coin-change/
// 322. 零钱兑换

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][j] -- 从前i个元素中能选到刚好总金额为j的最少硬币个数
        int n = coins.size();
        // 优化
        vector<int> dp(amount + 1);
        for (int j = 1; j <= amount; ++j)
            dp[j] = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                if (dp[j - coins[i - 1]] != -1)
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};