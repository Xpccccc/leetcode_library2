

//167. 两数之和 II - 输入有序数组
//https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        if (numbers[left] + numbers[right] < target) {
            left++;
        } else if (numbers[left] + numbers[right] > target) {
            right--;
        } else {
            res[0] = left;
            res[1] = right;
            return res;
        }
    }
    res[0] = -1;
    res[1] = -1;
    return res;
}