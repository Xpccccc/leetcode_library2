
//
// https://leetcode.cn/problems/valid-triangle-number/
// 611. 有效三角形的个数
class Solution {
public:
    int triangleNumber(vector<int> &nums) {

        // 使用双指针算法
        // 先排序，从右往左固定c
        // 重复下面过程
        // a + b > c -- 个数：r-l ，r--
        // a + b <= c -- l++

        int n = nums.size();
        if (n == 1 || n == 2)
            return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = n - 1; i >= 2; --i) {
            int c = nums[i];
            int right = i - 1, left = 0;
            // a + b <= c
            while (left < right) {
                while (nums[left] + nums[right] <= c && left < right) {
                    left++;
                }
                // a + b > c 或者left == right
                ret += right - left;

                right--;
            }
        }

        return ret;
    }
};