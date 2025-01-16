
// https://leetcode.cn/problems/longest-increasing-subsequence/
// 300. 最长递增子序列

// 记忆化搜索
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;

        vector<int> memo(n);
        for (int i = 0; i < n; ++i) {
            ret = max(ret, dfs(i, nums, memo));
        }
        return ret;
    }

    int dfs(int pos, vector<int>& nums, vector<int>& memo) {
        if (memo[pos])
            return memo[pos];
        int ret = 1;
        for (int i = pos + 1; i < nums.size(); ++i) {
            if (nums[pos] < nums[i]) {
                ret = max(ret, dfs(i, nums, memo) + 1);
            }
        }
        memo[pos] = ret;
        return ret;
    }
};Ï

// 动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] -- 以i为结尾的最长严格递增子序列的长度
        int n = nums.size();
        vector<int> dp(n, 1); // 最短长度为1
        int ret = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]); // 在这层for循环的最大长度
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};