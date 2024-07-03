
// https://leetcode.cn/problems/find-peak-element/
// 162. 寻找峰值

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 二段性
        // 二分
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > nums[mid - 1])
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};