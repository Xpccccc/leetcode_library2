
// https://leetcode.cn/problems/wildcard-matching/
// 44. 通配符匹配

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
        for (int i = 1; i <= n; ++i) {
            if (p[i] == '*')
                dp[0][i] = true;
            else
                break; // 如果存在不是*的字符，那么后肯定是匹配不了的
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*')
                    dp[i][j] =
                        dp[i][j - 1] ||
                        dp[i - 1]
                          [j]; // 这里是'*'，匹配一个但是不舍去，或者使用数学方法，匹配1个，2个，3个...使用错位相减法推导出dp[i
                               // - 1][j]
                else if (s[i] == p[j]) {
                    // 普通字符
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};