//
// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
// LCR 179. 查找总价格为目标值的两个商品

class Solution {
public:
    vector<int> twoSum(vector<int> &price, int target) {
        // 使用双指针算法
        // 因为数组已经有序
        int left = 0, right = price.size() - 1;
        vector<int> ret;
        while (left < right) {
            if (price[left] + price[right] == target) {
                ret.push_back(price[left]);
                ret.push_back(price[right]);
                return ret;
            } else if (price[left] + price[right] < target) {
                // 当前两个价格小于目标价格，说明left位置和right左边的所有位置的值相加都会小于目标值
                left++;
            } else {
                // 当前两个价格大于目标价格，说明right位置和left右边的所有位置的值相加都会大于目标值
                right--;
            }

        }
        return ret;
    }
};