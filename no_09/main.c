#include <stdbool.h>
#include <stdlib.h>
//9、判断回文数
bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int y = x;
    int len = 0;//x的位数
    while (y) {
        y = y / 10;
        len++;
    }
    int *arr = NULL;
    arr = (int *) malloc(sizeof(int) * len);//开辟空间
    y = x;//重置y
    int l = len;//防止len被修改
    while (y) {
        arr[l - 1] = y % 10;//数组从后往前存
        y = y / 10;
        l--;//从后往前存
    }
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] == arr[right]) {//前后相等则继续比较
            left++;
            right--;
        } else
            return false;  //前后不相等则直接返回
    }
    return true;
}