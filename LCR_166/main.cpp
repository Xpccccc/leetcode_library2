
// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
// LCR 166. 珠宝的最高价值

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        // 1.创建dp表
        int m = frame.size(), n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[i][j] 表示[0,0]到[i,j]的最大价值
        // 2.初始化
        // 3.填表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
            }
        }

        // 4.返回值
        return dp[m][n];
    }
};