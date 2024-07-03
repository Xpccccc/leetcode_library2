
// https://leetcode.cn/problems/house-robber-ii/
// 213. 打家劫舍 II

class Solution {
    int robCom(vector<int>& nums,int left,int right) {
        // 创建dp表
        // dp[i] -- 从起始位置到当前位置的最大金额
        // f[i]  -- 当前位置偷，那么上一个位置一定不偷
        // g[i] -- 当前位置不偷，那么上一个位置可以偷或不偷
        int n = right - left + 1;
        if(n == 0) return 0;
        vector<int> f(n), g(n);
        // 初始化
        f[0] = nums[left];
        // 填表
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1] + nums[++left];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 返回值
        return max(f[n - 1], g[n - 1]);
    }
public:
    int rob(vector<int>& nums) {
        // 第一个位置填或者第二个位置填
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robCom(nums,0,n-2),robCom(nums,1,n-1));
    }
};