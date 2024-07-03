
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// 309. 买卖股票的最佳时机含冷冻期

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] -- 当前位置已买入的最大利润
        // dp[i][1] -- 当前位置已卖出的最大利润
        // dp[i][2] -- 当前位置冷冻期的最大利润
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0]; // 第一天可已买入的最大利润

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        return max(dp[n-1][1],dp[n-1][2]);
    }
};