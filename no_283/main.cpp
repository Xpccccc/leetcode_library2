

// 283. 移动零
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        // 使用双指针

        int finish = -1;
        int cur = 0;

        // [0,finish] [finish+1,cur-1] [cur,n-1]
        while (cur < nums.size()) {
            if (nums[cur] != 0) {
                swap(nums[finish + 1], nums[cur]);
                ++finish;
            }
            ++cur;
        }
    }
};