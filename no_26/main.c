//26. 删除有序数组中的重复项
//题目链接https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(int *nums, int numsSize) {
    int count = 0;
    int i = 0;//指针i
    int j = 1;//指针j
    while (j < numsSize) {//指针j到数组末尾
        if (nums[i] == nums[j]) {
            j++;//前后两个元素相等的话，只需要移动后面的j指针
            count++;//记录删除的元素个数
        } else {
            nums[i + 1] = nums[j];//指针i和指针j所指元素不相等时，则将i所指元素后一个位置填上j所指元素（相当于删除了i与j之间相等的元素）
            i++;//i，j指针同步后移
            j++;
        }
    }
    return numsSize - count;
}