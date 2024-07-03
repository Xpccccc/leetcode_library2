#include <stdio.h>
#include <stdbool.h>
#include <tgmath.h>

//202. 快乐数
//题目链接https://leetcode.cn/problems/happy-number/


class Solution{
        public:
        // 下一个位置的数
        int nextnum(int n) {
            int sum = 0;
            while (n) {
                int x = n % 10;
                sum += x * x;
                n /= 10;
            }

            return sum;
        }

        bool isHappy(int n) {
            // 快慢指针
            int slow = n, fast = nextnum(n);
            while (slow != fast) {
                // 慢指针走一步
                slow = nextnum(slow);
                // 快指针走两步
                fast = nextnum(nextnum(fast));
            }

            return slow == 1;
        }
};

//bool isHappy(int n) {
//    //每个数辗转反侧之后都会变为个位数；
//    if (1111111 == n)//这是快乐数？？
//        return true;
//    int sum = 0;
//    int temp = n;
//    while (sum != 1) {
//        sum = 0;
//        while (temp) {
//            sum += pow(temp % 10, 2);
//            temp /= 10;
//        }
//        if (sum <= 9 && sum != 1)
//            return false;
//        temp = sum;
//    }
//    return true;
//}
//
//int main() {
//    int res = isHappy(101);
//    printf("%d\n", res);
//    return 0;
//}
