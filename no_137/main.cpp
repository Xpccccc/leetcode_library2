
// https://leetcode.cn/problems/single-number-ii/
// 137. 只出现一次的数字 II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 计算nums所有数的对应每个比特位相加的个数，最终对应比特位要么是3n个，要么是3n+1个
        // 如果是3n+1个，那么多出来的1就是出现一次的那个数
        int ret = 0;
        for (int i = 0; i <= 31; ++i) {
            int sum = 0;
            for (auto e : nums) {
                if (((e >> i) & 1) == 1)
                    sum++;
            }
            if (sum % 3 == 1)
                ret |= (1 << i);
        }
        return ret;
    }
};