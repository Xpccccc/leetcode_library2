
// https://leetcode.cn/problems/3sum/
// 15. 三数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // 双指针算法 -- 固定一个数，再使用双指针算法
        // 先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > 0)
                break; // 后面不存在三元组

            int fixed = -nums[i];
            int left = i + 1, right = n - 1;
            // 双指针
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum > fixed) {
                    // 右边数大
                    right--;
                } else if (sum < fixed) {
                    // 左边数小
                    left++;
                } else {
                    // 相等
                    ret.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // 去掉重复left 和 right
                    while (nums[left] == nums[left - 1] && left < right) {
                        ++left;
                    }
                    while (nums[right] == nums[right + 1] && left < right) {
                        --right;
                    }
                }
            }
            ++i;
            while (i < n && nums[i] == nums[i - 1])
                ++i; // 跳过重复固定元素
        }
        return ret;
    }
};