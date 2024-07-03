
// https://leetcode.cn/problems/n-th-tribonacci-number/
// 1137. 第 N 个泰波那契数

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        vector<long long> dp(n + 1);
        dp[0] = 0, dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};