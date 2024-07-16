
// https://leetcode.cn/problems/sort-colors/
// 75. 颜色分类
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // left指向0的最右边，right指向2的最左边，i指向dangqianyaunsu
        // [0.left][left+1,i][i,right-1][right,n]
        int n = nums.size();
        int left = -1, right = n;
        for (int i = 0; i < right;) {
            if (nums[i] == 0) {
                swap(nums[++left], nums[i++]);
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[--right], nums[i]);
            }
        }
    }
};