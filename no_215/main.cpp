
// https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 215. 数组中的第K个最大元素

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return qsort(nums, 0, nums.size() - 1, k);
    }

    int qsort(vector<int>& nums, int l, int r, int k) {
        if (l == r)
            return nums[l];
        // 获取随机基准元素
        int key = getRandom(nums, l, r);
        int i = l, left = l - 1, right = r + 1;
        while (i < right) {
            if (nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == key)
                ++i;
            else
                swap(nums[--right], nums[i]);
        }

        //  分情况讨论
        int c = r - right + 1;    // 当前大于key的个数
        int b = right - left - 1; // 当前等于key的个数
        if (c >= k)               // 去右边找
            return qsort(nums, right, r, k);
        else if (b + c >= k) // 去中间找
            return key;
        else // 去左边找，因为中间和右边的大于等于key个数不够
            return qsort(nums, l, left, k - b - c);
    }

    int getRandom(vector<int>& nums, int left, int right) {
        return nums[rand() % (right - left + 1) + left];
    }
};