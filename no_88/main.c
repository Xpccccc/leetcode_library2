
//88. 合并两个有序数组
//题目链接https://leetcode.cn/problems/merge-sorted-array/
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    //每次都比两个数组最大的数，从后往前遍历插入
    while (m > 0 && n > 0) {
        if (nums1[m - 1] >= nums2[n - 1]) {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        } else {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
    if (n == 0) {
        return;
    }
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];//nums1剩余位置插入nums2的剩余元素
        }
    }

}