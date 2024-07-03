
// https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/
// 446. 等差数列划分 II - 子序列

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i][j] -- 以j为结尾，i为倒数第二的最长等差子序列的个数
        int n = nums.size();
        unordered_map<long long, vector<int>> hash; // 倒数第三的下标个数可能很多个
        for (int i = 0; i < n; ++i)
            hash[nums[i]].push_back(i);
        vector<vector<int>> dp(n, vector<int>(n));
        int ret = 0;
        for (int j = 2; j < n; ++j) { // 固定倒数第一的元素
            for (int i = j - 1; i >= 1; --i) {
                long long a = (long long)2 * nums[i] - nums[j];
                if (hash.count(a)) { // 存在
                    for (auto index : hash[a]) {
                        if (index < i) // 符合要求
                            dp[i][j] += dp[index][i] + 1;
                    }
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};