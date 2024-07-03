
// https://leetcode.cn/problems/profitable-schemes/
// 879. 盈利计划

class Solution {
public:
    const int N = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        // dp[i][j][k] --  从前i个元素中挑选到成员不超过j，利润不低于k的方案总数
        int len = group.size();
        // 优化
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        // 初始化
        for (int j = 0; j <= n; ++j)
            dp[j][0] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = n; j >= group[i - 1]; --j) {
                for (int k = 0; k <= minProfit; ++k) {
                    dp[j][k] += dp[j - group[i - 1]][max(0, k - profit[i - 1])]; // 如果当前利润已经能达到所需最低利润，那么前面的就需要最低利润为0
                    dp[j][k] %= N;
                }
            }
        }
        return dp[n][minProfit];
    }
};