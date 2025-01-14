
// https://leetcode.cn/problems/unique-paths/
// 62. 不同路径


// 记忆化搜索
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1));
        return dfs(m, n, memo);
    }

    int dfs(int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j]) {
            return memo[i][j];
        }
        if (i == 0 || j == 0)
            return 0;
        if (i == 1 && j == 1) {
            memo[i][j] = 1;
            return 1;
        }
        memo[i][j] = dfs(i - 1, j, memo) + dfs(i, j - 1, memo);
        return memo[i][j];
    }
};

// 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 多开一行一列
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        // 第一行和第一列初始化为1
        for (int i = 0; i <= n; ++i)
            dp[0][i] = 1;
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};