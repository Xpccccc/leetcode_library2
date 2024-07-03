

#include <string.h>
#include <stdlib.h>

//求两个字符串的公共前缀
char *CommonPrefix(char *str1, char *str2) {
    char *arr = NULL;
    int co_len = 0;//共同前缀长度
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        if (str1[i] == str2[i]) {
            co_len++;//共同前缀长度
        } else {
            break;
        }
    }
    if (0 == co_len)
        return "";
    arr = (char *) malloc(sizeof(char) * co_len + 1);//开辟空间,+1是为了加上字符串末尾符号\0
    for (int i = 0; i < co_len; i++) {
        arr[i] = str1[i];
    }
    arr[co_len] = 0;
    return arr;
}

//14. 最长公共前缀
char *longestCommonPrefix(char **strs, int strsSize) {
    if (1 == strsSize)
        return strs[0];
    if (2 == strsSize)
        return CommonPrefix(strs[0], strs[1]);//第一个和第二个字符串的最长前缀
    char *ret = CommonPrefix(strs[0], strs[1]);//记录第一个和第二个字符串的最长前缀
    for (int i = 2; i < strsSize; i++) {
        ret = CommonPrefix(*(strs + i), ret);//从第三个字符串一直向后比较，每次返回上一次的对比结果
    }
    return ret;
}