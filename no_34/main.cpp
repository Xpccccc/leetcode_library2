//
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// 34. 在排序数组中查找元素的第一个和最后一个位置

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // 二段性 -- 二分

        // 边界情况
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        // 找区间左端点
        int left = 0, right = n - 1;
        int begin = 0;
        while (left < right) { // 这里不能 <= ，会出现死循环
            // 如果int mid = left + (right - left + 1) / 2;肯定不行，当此时left和right靠近的时候，只有两个值，如果刚好right和mid相等且都是target，那么right就不会动，left也不会动，直接死循环了      
            // 这个就不会，此时left和right靠近的时候，只有两个值，left和target相等的时候，right会移到mid的位置      
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        // left == right
        if (nums[left] == target)
            begin = left;
        else
            return {-1, -1};

        // 找右端点
        left = 0, right = n - 1;
        while (left < right) { // 这里不能 <= ，会出现死循环
            // 如果int mid = left + (right - left ) / 2;肯定不行，当此时left和right靠近的时候，只有两个值，如果刚好left和mid相等且都是target，那么left就不会动，right也不会动，直接死循环了
            // 这个就不会，此时left和right靠近的时候，只有两个值，right和target相等的时候，left会移到mid的位置
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        // left == right
        // 左端点有，那右端点一定有
        return {begin, right};
    }
};