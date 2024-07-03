#include <stdio.h>

//169. 多数元素
//题目链接https://leetcode.cn/problems/majority-element/submissions/

int majorityElement(int *nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    //先排序，冒泡排序
    int flag = 0;
    for(int i=0; i<numsSize; i++){
        flag = 0;
        for(int j =0; j<numsSize-1-i; j++){
            if(nums[j]>nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;//此趟已经有序，不用再继续比较了
    }
    //因为数组总是存在多数元素，所以排序完的数组的最多元素肯定在最中间位置
    return nums[numsSize/2];
}
