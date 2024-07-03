
//69. x 的平方根
//题目链接https://leetcode.cn/problems/sqrtx/
int mySqrt(int x) {
    long long a = 1;
    while (a * a <= x) {//a的平方小于x则一直让a自增
        a++;
    }
    return a - 1; //向下取整
}