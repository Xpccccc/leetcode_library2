
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
// 467. 环绕字符串中唯一的子字符串

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        // dp[i] -- 以i结尾非空子串数量，且在base中出现
        int n = s.size();
        vector<int> dp(n, 1); // 当前最少有一个非空子串
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            if(s[i] == s[i-1] + 1 || (s[i-1] == 'z' && s[i] == 'a'))   
                dp[i] +=dp[i-1];
        }
        // 这个时候，dp里面可能会有重复子串，得去重
        int hash[26] = {0};
        for (int i = 0; i < n; ++i) {
            if (hash[s[i] - 'a'] < dp[i])
                hash[s[i] - 'a'] = dp[i];
        }
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            ret += hash[i];
        }
        return ret;
    }
};