
// https://leetcode.cn/problems/sort-an-array/
// 912. 排序数组

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int key = GetRandom(nums, l, r);
        int i = l, left = l - 1, right = r + 1; // 用颜色分类的思想
        while (i < right) {
            if (nums[i] < key) {
                swap(nums[++left], nums[i++]);
            } else if (nums[i] == key) {
                ++i;
            } else {
                swap(nums[--right], nums[i]);
            }
        }
        // [l,left][left+1,right-1][right,r] 其中[left+1,right-1]是key
        qsort(nums, l, left);
        qsort(nums, right, r);
    }

    int GetRandom(vector<int>& nums, int left, int right) {
        int r = rand();
        return nums[r % (right - left + 1) + left];
    }
};