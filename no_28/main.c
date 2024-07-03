#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////kmp算法
//int strStr(char *haystack, char *needle) {
//    int len2 = strlen(needle);
//    int *next = (int *) malloc(sizeof(int) * len2 + 1);//开辟空间
//    //先获得模式串的next值
//    int i = 1;
//    int j = 0;
//    next[1] = 0;
//    while (i < len2) {
//        if (j == 0 || needle[i] == needle[j]) {
//            ++i;
//            ++j;
//            next[i] = j;
//        } else {
//            j = next[j];
//        }
//    }
//
//    i = 1;
//    j = 1;
//    int len1 = strlen(haystack);
//    while (i <= len1 && j <= len2) {
//        if (j == 0 || haystack[i] == needle[j]) {
//            ++i;
//            ++j;
//        } else {
//            j = next[j];
//        }
//    }
//    if (j > len2)
//        return i - len2;
//    else
//        return -1;
//}

//28. 找出字符串中第一个匹配项的下标
//题目链接https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
int strStr(char *haystack, char *needle) {
    //暴力
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int count = 0;//记录当前能匹配的长度
    for (int i = 0, j = 0; i < len1 && j < len2;) {
        if (haystack[i] == needle[j]) {
            count++;//记录当前能匹配的长度
            i++;//i,j一起向后移
            j++;
            if (len2 == count) {
                return i - count;//从i向前数count个字符
            }
        } else {
            i = i - count + 1;//i回到上一次的开始匹配的位置向后一位
            j = 0;//不匹配则needle继续从头开始和haystack比对
            count = 0;
        }
    }
    return -1;//不匹配
}

int main() {
    char str1[100] = {0};
    char str2[100] = {0};
    gets(str1);
    gets(str2);
    int ret = strStr(str1, str2);
    printf("%d\n", ret);
    return 0;
}

