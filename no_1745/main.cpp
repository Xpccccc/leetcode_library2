
// https://leetcode.cn/problems/palindrome-partitioning-iv/
// 1745. 分割回文串 IV

class Solution {
public:
    bool checkPartitioning(string s) {
        // dp[i][j] -- 以i，j分别为左右端点的子串是否为回文子串
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i == j || i + 1 == j) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // 分割成三个区间[0][i-1] [i][j-1] [j][n-1]
                if (dp[0][i - 1] && dp[i][j - 1] && dp[j][n - 1])
                    return true;
            }
        }
        return false;
    }
};