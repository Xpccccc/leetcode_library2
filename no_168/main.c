#include <stdio.h>
#include <stdlib.h>

//168. Excel表列名称
//题目链接https://leetcode.cn/problems/excel-sheet-column-title/

char *convertToTitle(int n) {
    char* str = (char*) malloc(sizeof (char )*8);//数组长度最长不超过8，int的值就那么大
    int p = 7;//从后往前插入
    str[p] = '\0';
    while (n) {
        str[--p] = 'A' + ((n - 1) % 26);
        n = (n - 1) / 26;//A的值从1开始
    }
    return &str[p];//返回最前面的字符地址
}

int main() {
    char *ret = convertToTitle(2147483647);
    printf("%s\n", ret);
    return 0;
}
