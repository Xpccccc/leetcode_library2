
// https://leetcode.cn/problems/word-break/
// 139. 单词拆分

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for (auto& e : wordDict)
            us.insert(e);
        // dp[i] -- 以i为结尾能拼出单词
        int n = s.size();
        vector<bool> dp(n + 1); // 多开一个空间
        dp[0] = true;           // 保证dp后面正确
        s = ' ' + s;            // 有效字符串下标+1
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                if (dp[j - 1] && us.count(s.substr(j, i - j + 1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};