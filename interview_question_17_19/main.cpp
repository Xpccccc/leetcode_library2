
// https://leetcode.cn/problems/missing-two-lcci/
// 面试题 17.19. 消失的两个数字

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        // 先把nums的元素和1～N的元素全部异或到一起，得到消失的像个数字a和b
        int tmp = 0;
        for (int i = 1; i <= nums.size() + 2; ++i) {
            tmp ^= i;
        }
        for (auto e : nums)
            tmp ^= e;

        // 分离tmp为a和b
        // 找到tmp第一个比特位为1的位置，这就是分离a和b的关键
        int index = 0;
        for (int i = 0; i <= 31; ++i) {
            if (((tmp >> i) & 1) == 1) {
                index = i;
                break;
            }
        }
        int a = 0, b = 0;
        for (auto e : nums) {
            if ((e >> index) & 1 == 1)
                a ^= e;
            else
                b ^= e;
        }
        for (int i = 1; i <= nums.size() + 2; ++i) {
            if ((i >> index) & 1 == 1)
                a ^= i;
            else
                b ^= i;
        }
        return {a, b};
    }
};