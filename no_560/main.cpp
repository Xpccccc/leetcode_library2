//
// https://leetcode.cn/problems/subarray-sum-equals-k/
// 560. 和为 K 的子数组

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和 + 哈希表
        unordered_map<int, int> hash;
        hash[0] = 1; // 前缀和为0的一定会有一个，也就是在[0,i]的和等于k的时候，也算是一个有效的区间，那么找sum-k 就得去 [0,-1]找，这个区间不存在
        int sum = 0, ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (hash.count(sum - k)) // 找前缀和为sum-k的个数
                ret += hash[sum - k];
            hash[sum]++; // 从0到i的前缀和 都放到hash表中
        }

        return ret;
    }
};