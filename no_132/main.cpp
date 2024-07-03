
// https://leetcode.cn/problems/palindrome-partitioning-ii/
// 132. 分割回文串 II

class Solution {
public:
    int minCut(string s) {
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

        // f[i] -- 以i为结尾的，最少切割次数
        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (dp[0][i]) {
                f[i] = 0;
                continue;
            }
            for (int j = i; j > 0; --j) { // j = 0 上面已经考虑
                if (dp[j][i]) {
                    f[i] = min(f[j - 1] + 1, f[i]);
                }
            }
        }
        return f[n - 1];
    }
};