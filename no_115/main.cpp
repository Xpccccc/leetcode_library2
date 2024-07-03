
// https://leetcode.cn/problems/distinct-subsequences/
// 115. 不同的子序列

class Solution {
public:
    const int N = 1e9 + 7;
    int numDistinct(string s, string t) {
        // dp[i][j] -- s在[0,j]的子序列中出现t以i结尾的字符串的个数
        int m = t.size(), n = s.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        for (int i = 0; i <= n; ++i)
            dp[0][i] = 1; // 初始化
        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];// 相不相等都要去j-1位置看有没有t子串
                if (t[i] == s[j])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};