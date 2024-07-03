//
// https://leetcode.cn/problems/max-consecutive-ones-iii/
// 1004. 最大连续1的个数 III

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        // 滑动窗口
        // 题目转化：带k个0的最长子数组
        int hash[2] = {0};
        int left = 0, right = 0, n = nums.size();
        int len = 0;
        while (right < n) {
            // 进窗口
            hash[nums[right]]++;
            // 0的个数大于k，出窗口
            while (hash[0] > k) {
                hash[nums[left]]--;
                ++left;
            }
            // 更新结果
            len = max(right - left + 1, len);
            ++right;
        }
        return len;
    }
};