//
// https://leetcode.cn/problems/contiguous-array/
// 525. 连续数组

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 前缀和 + 哈希表
        // 转化 ： 把所有0变为-1
        // 找和为0的最长子数组
        for (auto& e : nums) {
            if (e == 0)
                e = -1;
        }
        int len = 0;
        unordered_map<int, int> hash;
        int sum = 0;
        hash[0] = -1; // 前缀和为0，默认有一个下标是-1
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (!hash.count(sum)) // 不存在就更新，存在不需要更新，因为已经是最左边了
                hash[sum] = i;
            len = max(len, i - hash[sum]); // 取最大区间
        }
        return len;
    }
};