
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//20. 有效的括号
bool isValid(char *s) {
    int len = strlen(s);//确定要创建的数组长度
    char *arr = (char *) malloc(sizeof(char) * len + 1);//开辟空间
    int top = -1;//栈顶指针
    for (int i = 0; i < len; i++) {
        if (-1 != top) {//栈不空
            if (s[i] == ')' && arr[top] == '(') {
                arr[top] = '\0';//括号匹配出栈
                top--;
            } else if (s[i] == ']' && arr[top] == '[') {
                arr[top] = '\0';//括号匹配出栈
                top--;
            } else if (s[i] == '}' && arr[top] == '{') {
                arr[top] = '\0';//括号匹配出栈
                top--;
            } else {
                top++;
                arr[top] = s[i];//括号不匹配入栈
            }
        } else {//栈空
            top++;
            arr[top] = s[i];
        }
    }
    if (-1 == top)
        return true;
    else
        return false;
}
