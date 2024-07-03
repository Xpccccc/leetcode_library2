
// https://leetcode.cn/problems/ones-and-zeroes/
// 474. 一和零

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 二维费用的01背包问题
        // dp[i][j][k] --
        // 从前i个字符串中选择字符0不超过j，字符1不超过k的最长子集长度
        int len = strs.size();
        // 优化
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= len; ++i) {
            // 计算当前字符串01个数
            int a = 0, b = 0;
            for (auto ch : strs[i - 1]) {
                if (ch == '0')
                    ++a;
                else
                    ++b;
            }
            for (int j = m; j >= a; --j)
                for (int k = n; k >= b; --k)
                    dp[j][k] = max(dp[j][k], dp[j - a][k - b] + 1);
        }
        return dp[m][n];
    }
};