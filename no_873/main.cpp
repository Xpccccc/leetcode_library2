
// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
// 873. 最长的斐波那契子序列的长度

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // dp[i][j] -- 以j结尾，i倒数第二的最长的斐波那契式的子序列的长度
        int n = arr.size();
        unordered_map<int, int> hash; // 存所有dp倒数第三个值的下标
        for (int i = 0; i < arr.size(); ++i)
            hash[arr[i]] = i;
        int ret = 2;
        vector<vector<int>> dp(n, vector<int>(n, 2)); // 最短斐波那契式长度2
        for (int j = 2; j < n; ++j) {
            for (int i = j - 1; i >= 1; --i) {
                int a = arr[j] - arr[i];
                if (a < arr[i] && hash.count(a)) {
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                ret = max(dp[i][j], ret); // 这里每次循环会换i，不能break
            }
        }
        return ret < 3 ? 0 : ret;
    }
};