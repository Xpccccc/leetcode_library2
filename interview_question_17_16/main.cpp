
// https://leetcode.cn/problems/the-masseuse-lcci/
// 面试题 17.16. 按摩师

class Solution {
public:
    int massage(vector<int>& nums) {
        // 创建dp表
        // dp[i] -- 表示到i位置的最长分钟数
        // f[i] -- 表示i位置一定选 ，那么i-1位置一定不选
        // g[i] -- 表示i位置一定不选，那么i-1位置可以选也可以不选
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> f(n), g(n);
        // 初始化
        f[0] = nums[0];
        // 填表
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 返回值
        return max(f[n - 1], g[n - 1]);
    }
};