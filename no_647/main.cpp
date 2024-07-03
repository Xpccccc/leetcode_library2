
// https://leetcode.cn/problems/palindromic-substrings/
// 647. 回文子串

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j] -- 以i，j分别为左右端点的子串是否为回文子串
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i == j || i + 1 == j) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j])
                    ret += 1;
            }
        }
        return ret;
    }
};