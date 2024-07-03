
// https://leetcode.cn/problems/interleaving-string/
// 97. 交错字符串

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] -- 以s1以i结尾，s2以j结尾能否组成s3以j结尾
        int m = s1.size(), n = s2.size();
        int k = s3.size();
        if (m + n != k)
            return false;
        // 下标都加1，方便s3的下标映射
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化
        // s1为空看s2
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (s2[j] == s3[j])
                dp[0][j] = true;
            else
                break;
        }
        // s2为空看s1
        for (int i = 1; i <= m; ++i) {
            if (s1[i] == s3[i])
                dp[i][0] = true;
            else
                break;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // dp[i][j] = (s3[i+j] == s1[i] && dp[i-1][j])||(s3[i+j] == s2[j] && dp[i][j-1]);
                if (s3[i + j] == s1[i])
                    dp[i][j] = dp[i - 1][j];
                if (s3[i + j] == s2[j]) // 不能else if，两个条件都要判断
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};