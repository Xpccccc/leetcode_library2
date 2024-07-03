
//70. 爬楼梯
//题目链接https://leetcode.cn/problems/climbing-stairs/
int climbStairs(int n) {
    if (1 == n)
        return 1;
    if (2 == n)
        return 2;
    // return climbStairs(n-1)+climbStairs(n-2);//第一步走一步就剩下n-1步，第一步走两步就剩下n-2步 -- 太慢了
    int a = 1;//第一个数
    int b = 2;//第二个数
    int c = 0;//前两个数的和
    while (n - 2) {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;

}