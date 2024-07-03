
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
// 188. 买卖股票的最佳时机 IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i] -- 在i位置的最大利润
        // f[i][j] -- 在i位置，交易j次已买入的最大利润
        // g[i][j] -- 在i位置，交易j次已卖出的最大利润
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(k+1, -0x3f3f3f3f)),
            g(n, vector<int>(k+1, -0x3f3f3f3f));
        f[0][0] = -prices[0]; // 0位置已买入，交易0次的最大利润，交易1，2次的最大利润为-∞，不影响后面dp状态转移方程
        g[0][0] = 0; // 0位置已卖出，交易0次的最大利润，交易1，2次的最大利润为-∞，不影响后面dp状态转移方程
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] =
                    g[i - 1][j]; // 如果j - 1  < 0,说明没有上一次已买入的情况
                if (j - 1 >= 0)
                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        int mprofit = 0;
        for (int i = 0; i < k + 1; ++i) {
            mprofit = max(g[n - 1][i], mprofit);
        }
        return mprofit;
    }
};