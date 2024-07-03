
// https://leetcode.cn/problems/delete-and-earn/
// 740. 删除并获得点数

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxnum = 0; // 比nums最大值多1
        // 转化为打家劫舍
        for (auto e : nums) {
            maxnum = max(maxnum, e) +1;
        }
        vector<int> sum(maxnum);
        for (auto e : nums) {
            sum[e] += e;
        }

        vector<int> f(maxnum), g(maxnum);
        f[0] = sum[0];
        for (int i = 1; i < maxnum; ++i) {
            f[i] = g[i - 1] + sum[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[maxnum-1], g[maxnum-1]);
    }
};