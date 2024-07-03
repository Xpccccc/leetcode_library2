//
// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
// 153. 寻找旋转排序数组中的最小值

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 二段性
        // 二分
        if (nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[0])
                right = mid;
            else
                left = mid + 1;
        }
        // left == nums.size() - 1 可能是也可能不是
        if (left == nums.size() - 1 && nums[left] > nums[left - 1])
            return nums[0];
        else
            return nums[left];
    }
};