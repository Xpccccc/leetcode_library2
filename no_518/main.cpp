
// https://leetcode.cn/problems/coin-change-ii/
// 518. 零钱兑换 II

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j] -- 前i个元素中刚好凑成金额为j的组合数
        int n = coins.size();
        // 优化
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                if (dp[j - coins[i - 1]] != -1)
                    dp[j] += dp[j - coins[i - 1]];
            }
        }
        return dp[amount];
    }
};