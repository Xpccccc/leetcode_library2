
// https://leetcode.cn/problems/regular-expression-matching/
// 10. 正则表达式匹配

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] -- p以j结尾能否匹配s以i结尾的子串
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // 初始化
        dp[0][0] = true; // 都是空肯定能匹配
        // 给s，p的下标加1
        s = " " + s;
        p = " " + p;
        // a* 可以变为 空或者a或者aa...
        for (int i = 2; i <= n; i += 2) {
            if (p[i] == '*')
                dp[0][i] = true;
            else
                break; // 如果存在不是*的字符，那么后肯定是匹配不了的
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j] == '*') {
                    if (p[j - 1] == '.') { // 前一个字符是'.'
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j]; // 匹配1个及以上
                    } else {
                        if (p[j - 1] == s[i])
                            dp[i][j] = dp[i][j - 2] || dp[i - 1][j]; //  匹配1个及以上，，也可以匹配空
                        else
                            dp[i][j] = dp[i][j - 2];
                    }
                } else {
                    // 普通字符 或者 '.'
                    if (p[j] == '.' || s[i] == p[j])
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};