
//136. 只出现一次的数字
//题目链接https://leetcode.cn/problems/single-number/
int singleNumber(int *nums, int numsSize) {
    int arr[30001] = {0};//一半的元素+1
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0)
            arr[nums[i]]++;//下标为nums[i]的元素值自增
    }
    for (int i = 0; i < 30001; i++) {
        if (arr[i] == 1) {//检查是哪个元素的值为1，其下标就是只出现一次的元素
            return i;
        }
    }
    //如果正数不存在出现一次的元素，则重置数组，判断负数
    for (int i = 0; i < 30001; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0)
            arr[-nums[i]]++;//下标为nums[i]的元素值自增
    }
    for (int i = 0; i < 30001; i++) {
        if (arr[i] == 1) {//检查是哪个元素的值为1，其下标就是只出现一次的元素
            return -i;
        }
    }
    return 30002;//表示不存在
}