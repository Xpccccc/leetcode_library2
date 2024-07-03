

//190. 颠倒二进制位
//题目链接https://leetcode.cn/problems/reverse-bits/

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res += ((n >> i) & 1) * pow(2, 31 - i);
    }
    return res;
}