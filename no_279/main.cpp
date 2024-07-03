
// https://leetcode.cn/problems/perfect-squares/
// 279. 完全平方数

class Solution {
public:
    int numSquares(int n) {
        // dp[i][j] -- 从前i个元素的下标的平方选到和为j的最少数量
        int m = sqrt(n);
        // 优化
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i * i; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};