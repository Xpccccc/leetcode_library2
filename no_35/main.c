

// 35. 搜索插入位置
// 题目链接https://leetcode.cn/problems/search-insert-position/

class Solution {
        public:
        int searchInsert(vector<int>& nums, int target) {
            // 二段性 -- 二分

            // 需要找到的值是要大于等于target的，及大于等于target的区间的左端点
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (nums[left] < target)
                left++;
            return left;
        }
};

//int searchInsert(int *nums, int numsSize, int target) {
//    int left = 0;
//    int right = numsSize - 1;
//    //小于最小值值和大于最大值情况
//    if (target > nums[right])
//        return numsSize;
//    if (target < nums[left])
//        return 0;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (target > nums[mid]) {
//            left = mid + 1;
//        } else if (target < nums[mid]) {
//            right = mid - 1;
//        } else {
//            return mid;//找到了返回下标
//        }
//    }
//    //没找到
//    return right + 1;
//}