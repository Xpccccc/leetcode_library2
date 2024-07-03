#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//219. 存在重复元素 II
//题目链接https://leetcode.cn/problems/contains-duplicate-ii/

typedef struct S {
    int val;//值
    int pos;//下标
} S;

int cmp(const void *p1, const void *p2) {
    int a = (*(S *) p1).val;
    int b = (*(S *) p2).val;
    return a - b;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    //开辟空间
    S *temp = (S *) malloc(sizeof(S) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i].pos = i;
        temp[i].val = nums[i];//记录好对应关系
    }
    //再按照结构体的值快速排序
    qsort(temp, numsSize, sizeof(S), cmp);
    for (int i = 0, j = 1; j < numsSize;) {
        if (temp[i].val != temp[j].val) {
            i++;
            j++;
        } else {
            if (abs(temp[i].pos - temp[j].pos) <= k)
                return true;
            i++;
            j++;
        }
    }
    return false;
}


int main() {
    int arr[] = {1, 0, 1, 1};
    containsNearbyDuplicate(arr, 4, 1);
    return 0;
}
