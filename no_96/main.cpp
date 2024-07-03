
// https://leetcode.cn/problems/unique-binary-search-trees/
// 96. 不同的二叉搜索树

class Solution {
public:
    int numTrees(int n) {
        // dp[i] -- 以i结尾的二叉搜索树的种数
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};