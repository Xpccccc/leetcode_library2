#include <stdio.h>
#include <stdbool.h>

//217. 存在重复元素
//题目链接https://leetcode.cn/problems/contains-duplicate/submissions/

int cmp(const void *p1, const void *p2) {
    int a = *(int *) p1, b = *(int *) p2;
    return a - b;
}

bool containsDuplicate(int *nums, int numsSize) {
    //快速排序
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0, j = 1; j < numsSize;) {
        if (nums[i] != nums[j]) {
            i++;
            j++;//继续向后判断
        } else
            return true;
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 1};
    containsDuplicate(arr, 4);
    return 0;
}
