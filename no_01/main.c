/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

//两数之和
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *result = NULL;
    result = (int *) malloc(sizeof(int) * 2);//开辟空间
    int i = 0;
    for (i = 0; i < numsSize - 1; i++) {
        int j = 0;
        for (j = i + 1; j < numsSize; j++) { //j每次从i的后一个位置开始，防止重复计算
            int sum = nums[i] + nums[j];//当前数组元素和后面某个元素的和
            if (sum == target) {
                result[0] = i;
                result[1] = j;//相等后的数值下标
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}