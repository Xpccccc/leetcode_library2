//
// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 209. 长度最小的子数组

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        // 滑动窗口
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0;
        int len = 1e5 + 10;
        while (right < n) {
            // 进窗口
            sum += nums[right];
            // 出窗口
            while (sum >= target) {
                // 计算长度，取最小
                len = min(right - left + 1, len);
                sum -= nums[left];
                ++left;
            }
            right++;
        }
        if (len == 1e5 + 10)
            return 0;
        else
            return len;
    }
};