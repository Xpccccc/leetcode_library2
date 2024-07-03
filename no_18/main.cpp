//
// https://leetcode.cn/problems/4sum/
// 18. 四数之和

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // 和三数之和类似
        //  先排序
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n;) {
            long long target1 = target - nums[i];
            for (int j = i + 1; j < n;) {
                long long target2 = target1 - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = nums[left] + nums[right];
                    if (sum > target2)
                        --right;
                    else if (sum < target2)
                        ++left;
                    else {
                        ret.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        // 去重
                        while (left < right && nums[left] == nums[left - 1])
                            ++left;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                }
                ++j;
                // 去重j
                while (j < n && nums[j] == nums[j - 1])
                    ++j;
            }
            ++i;
            // 去重i
            while (i < n && nums[i] == nums[i - 1])
                ++i;
        }
        return ret;
    }
};