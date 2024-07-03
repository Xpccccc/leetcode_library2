
// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// 1312. 让字符串成为回文串的最少插入次数

class Solution {
public:
    int minInsertions(string s) {
        // dp[i][j] -- 在区间[i,j]中，最少插入次数
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i == j)
                        dp[i][j] = 0;
                    else if (i + 1 == j)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};