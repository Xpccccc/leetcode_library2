
// https://leetcode.cn/problems/decode-ways/
// 91. 解码方法

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1); // 多开一个位置

        dp[0] = 1; // dp[2]位置如果能组合解码，那么是一种情况，使用dp[0]得是1
        dp[1] = s[1 - 1] != '0';
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] != '0') // i位置单独编码
                dp[i] += dp[i - 1];
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (10 <= t && t <= 26) // i位置和i-1位置编码
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};


// class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> dp(n);
//
//        // 处理边界情况
//        if (s[0] != '0')
//            dp[0] += 1;
//        if (n == 1)
//            return dp[0];
//        if (s[0] != '0' && s[1] != '0')
//            dp[1] += 1;
//        int t = (s[0] - '0') * 10 + s[1] - '0';
//        if (10 <= t && t <= 26)
//            dp[1] += 1;
//
//        for (int i = 2; i < n; ++i) {
//            if (s[i] != '0') // i位置单独编码
//                dp[i] += dp[i - 1];
//            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
//            if (10 <= t && t <= 26) // i位置和i-1位置编码
//                dp[i] += dp[i - 2];
//        }
//        return dp[n - 1];
//    }
//};