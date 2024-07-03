#include <string.h>
#include <stdlib.h>


//67. 二进制求和
//题目链接https://leetcode.cn/problems/add-binary/
char *addBinary(char *a, char *b) {
    // 求a，b的十进制值相加
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = len_a > len_b ? len_a + 2 : len_b + 2;//新的的字符串长度
    char *result = (char *) malloc(sizeof(char) * len);//可能进位了，再加上末位符\0
    result[len - 1] = '\0';
    int carry = 0;//进位
    for (int i = len_a - 1, j = len_b - 1, k = len - 2; (i >= 0) | (j >= 0); i--, j--, k--) {
        int sum = carry;
        sum += (i >= 0 ? (a[i] - '0') : 0);
        sum += (j >= 0 ? (b[j] - '0') : 0);
        carry = sum / 2;
        result[k] = '0' + sum % 2;
    }
    if (carry == 0)  //最后无进位，直接返回
        return result + 1; //当前位置的后一位
    result[0] = '1';    //有进位，补一个最高位
    return result;
}
