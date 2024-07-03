#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//66. 加一
//题目链接https://leetcode.cn/problems/plus-one/
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    for (int i = digitsSize - 1; i >= 0; --i) {
        if (digits[i] != 9) { //最后一个元素不为9
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
        //最后一个元素为9
        digits[i] = 0;//继续判断倒数第二个元素是不是9（--i）
    }
    //所有元素都是9
    //开辟空间
    int len = digitsSize + 1;
    *returnSize = len;
    int *result = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        result[i] = 0;
    }
    result[0] = 1;//进位
    return result;
}