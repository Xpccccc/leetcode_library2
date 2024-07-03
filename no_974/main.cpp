//
// https://leetcode.cn/problems/subarray-sums-divisible-by-k/
// 974. 和可被 K 整除的子数组

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 前缀和 + 哈希表
        unordered_map<int, int> hash;
        hash[0 % k] = 1; // [0,i]这个区间总和是k的倍数
        int sum = 0, ret = 0;
        for (auto e : nums) {
            sum += e;
            int r = (sum % k + k) % k; // 余数 -- 负数修正
            if (hash.count(r))
                ret += hash[r];
            hash[r]++;
        }

        return ret;
    }
};