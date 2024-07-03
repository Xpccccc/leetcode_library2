//
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
// 1658. 将 x 减到 0 的最小操作数

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        // 转化：找和为 sum - x 的最长子数组
        // 这个子数组必然是连续的，那么子数组左右肯定存在元素，这个元素的个数就是最少的

        // 使用滑动窗口
        int sum = 0;
        for (auto e: nums)
            sum += e;

        int target = sum - x;
        if (target < 0) return -1; // 总和比x小
        // 找和为target的最长子数组
        int left = 0, right = 0, tmpsum = 0, n = nums.size();
        int len = -1;
        while (right < n) {
            // 进窗口
            tmpsum += nums[right];
            while (tmpsum > target) {
                // 出窗口
                tmpsum -= nums[left];
                ++left;
            }
            if (target == tmpsum) {
                // 更新结果
                len = max(len, right - left + 1);
            }
            ++right;
        }
        return len == -1 ? -1 : n - len;
    }
};