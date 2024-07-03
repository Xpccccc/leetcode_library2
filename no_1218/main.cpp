
// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
// 1218. 最长定差子序列

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[i] -- 以i结尾的最长等差子序列的长度
        // 将dp[j] 和 arr[i]对应的差值存在哈希表中
        unordered_map<int, int> hash;
        hash[arr[0]] = 1; // dp[j] 最短长度为1
        int ret = 1;
        for (int i = 1; i < arr.size(); ++i) { // 从左往右，最右边的dp[j]会覆盖之前的
            hash[arr[i]] = hash[arr[i] - difference] + 1; // 如果dp[j]不存在，那么hash[arr[i] - difference]为0
            ret = max(ret, hash[arr[i]]); // dp[i]里面的最大值
        }
        return ret;

        // int n = arr.size();
        // vector<int> dp(n, 1);
        // int ret = 1;
        // for (int i = 1; i < n; ++i) {
        //     for (int j = i - 1; j >= 0; --j) { // n*n 时间复杂度超时
        //         if (arr[j] + difference == arr[i]) {
        //             dp[i] = dp[j] + 1;
        //             break;
        //         }
        //     }
        //     ret = max(ret, dp[i]);
        // }
        // return ret;
    }
};