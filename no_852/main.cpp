//
// https://leetcode.cn/problems/peak-index-in-a-mountain-array/
// 852. 山脉数组的峰顶索引

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 二段性
        int left = 1, right = arr.size() - 2; // 两个端点肯定不是结果
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1])
                left = mid;
            else if (arr[mid] < arr[mid - 1])
                right = mid - 1;
        }
        return left;
    }
};