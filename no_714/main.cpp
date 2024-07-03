
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// 714. 买卖股票的最佳时机含手续费

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0] -- 当前位置已买入的最大利润
        // dp[i][1] -- 当前位置已卖出的最大利润
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0] = -prices[0]; // 第一个位置已买入的最大利润
        dp[0][1] = 0; // 第一个位置已卖出的最大利润 -- 直接不买不卖

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n-1][1];
    }
};