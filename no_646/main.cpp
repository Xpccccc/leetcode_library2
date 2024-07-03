
// https://leetcode.cn/problems/maximum-length-of-pair-chain/
// 646. 最长数对链

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // dp[i] -- 以i结尾的最长数对链的长度
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int ret = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};