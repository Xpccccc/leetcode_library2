
// https://leetcode.cn/problems/longest-palindromic-substring/
// 5. 最长回文子串

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] -- 以i，j分别为左右端点的子串是否为回文子串
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int retlen = 1;
        int begin = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i == j || i + 1 == j) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) {
                    if (retlen < j - i + 1) {
                        begin = i;
                        retlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(begin, retlen);
    }
};