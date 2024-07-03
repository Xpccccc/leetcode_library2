
//27. 移除元素
//题目链接https://leetcode.cn/problems/remove-element/
int removeElement(int* nums, int numsSize, int val){
    int count = 0;//记录当前元素需要向前移动的个数
    for(int i=0; i<numsSize; i++){
        if(nums[i] == val){
            count++;
        }
        else{
            nums[i-count] = nums[i];//当前元素向前移动count位
        }
    }
    return numsSize-count;
}