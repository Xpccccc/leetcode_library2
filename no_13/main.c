#include <stdio.h>

//3. 罗马数字转整数
int romanToInt(char *s) {
    int sum = 0;
    while (*s != '\0') {
        //判断I后面字符
        if (*s == 'I') {
            if (*(s + 1) == 'V') {
                sum += 4;
                s += 2;//指针后移两个位置
            } else if (*(s + 1) == 'X') {
                sum += 9;
                s += 2;//指针后移两个位置
            } else {
                sum += 1;
                s++;//指针后移
            }

        }
        if (*s == 'X') {
            if (*(s + 1) == 'L') {
                sum += 40;
                s += 2;//指针后移两个位置
            } else if (*(s + 1) == 'C') {
                sum += 90;
                s += 2;//指针后移两个位置
            } else {
                sum += 10;
                s++;//指针后移
            }

        }
        if (*s == 'C') {
            if (*(s + 1) == 'D') {
                sum += 400;
                s += 2;//指针后移两个位置
            } else if (*(s + 1) == 'M') {
                sum += 900;
                s += 2;//指针后移两个位置
            } else {
                sum += 100;
                s++;//指针后移
            }

        }
        if (*s == 'V') {
            sum += 5;
            s++;//指针后移
        }
        if (*s == 'L') {
            sum += 50;
            s++;//指针后移
        }
        if (*s == 'C') {
            sum += 100;
            s++;//指针后移
        }
        if (*s == 'D') {
            sum += 500;
            s++;//指针后移
        }
        if (*s == 'M') {
            sum += 1000;
            s++;//指针后移
        }
    }
    return sum;
}

int main() {
    char arr[10] = {0};
    scanf("%s", arr);
    printf("%d", romanToInt(arr));
    return 0;
}
