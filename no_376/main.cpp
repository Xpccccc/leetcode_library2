
// https://leetcode.cn/problems/wiggle-subsequence/
// 376. 摆动序列

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // dp[i] -- 以i为结尾的最长摆动子序列长度
        // f[i] -- 以i为结尾的，i位置状态为上升趋势，最长摆动子序列长度
        // g[i] -- 以i为结尾的，i位置状态为上升趋势，最长摆动子序列长度
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1); // 最短为1
        int ret = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i])
                    f[i] = max(g[j] + 1, f[i]);
                else if (nums[j] > nums[i])
                    g[i] = max(f[j] + 1, g[i]);
            }
            ret = max(g[i], f[i]);
        }
        return ret;
    }
};