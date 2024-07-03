#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//125. 验证回文串
//题目链接https://leetcode.cn/problems/valid-palindrome/
bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] >= 'A' && s[left] <= 'Z')
            s[left] = s[left] + 32;//大写转小写
        if (s[right] >= 'A' && s[right] <= 'Z')
            s[right] = s[right] + 32;
        if (((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= '0' && s[left] <= '9')) &&
            ((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= '0' && s[right] <= '9'))) {//判断字符是小写字母或者是数字
            if (s[left] != s[right])
                return false;//不相等直接返回
            else {
                left++;
                right--;
            }
        } else {
            //左边指向的不是字符或数字则left右移
            if (!((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= '0' && s[left] <= '9')))
                left++;
            //右边指向的不是字符或数字则right左移
            if (!((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= '0' && s[right] <= '9')))
                right--;
        }
    }
    return true;
}

int main() {
    char s[] = "8V8K;G;K;V;";
    isPalindrome(s);
    return 0;
}
