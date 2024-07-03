
// https://leetcode.cn/problems/longest-arithmetic-subsequence/
// 1027. 最长等差数列

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // dp[i][j] -- 以j为结尾，i为倒数第二的最长等差子序列的长度
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ret = 2;
        hash[nums[0]] = 0;

        for (int i = 1; i < n; ++i) { // 固定倒数第二的元素
            for (int j = i + 1; j < n; ++j) {
                int a = 2 * nums[i] - nums[j];
                if (hash.count(a)) { // 存在且下标一定小于i
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
            hash[nums[i]] = i; // 值相等会覆盖，只留最当前位置左边最右边的
        }

        // for (int j = 2; j < n; ++j) {
        //     for (int i = 1; i < j; ++i) {
        //         hash[nums[j]] =
        //             j; //
        //             这样不行，值相等会覆盖，只留最当前位置左边最右边的，但是i每次都会回去，会重新覆盖
        //         int a = 2 * nums[i] - nums[j];
        //         if (hash.count(a) && hash[a] < i) { // 存在且下标小于i
        //             dp[i][j] = dp[hash[a]][i] + 1;
        //         }
        //         ret = max(ret, dp[i][j]);
        //     }
        // }
        return ret;
    }
};