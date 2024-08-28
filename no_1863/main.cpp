
// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/
// 1863. 找出所有子集的异或总和再求和

class Solution {
    int sum;
    int path;

public:
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return sum;
    }

    void dfs(vector<int>& nums, int pos) {
        sum += path;
        for (int i = pos; i < nums.size(); ++i) {
            path ^= nums[i];
            dfs(nums, i + 1);
            path ^= nums[i]; // 恢复现场
        }
    }
};