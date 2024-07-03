
// https://leetcode.cn/problems/container-with-most-water/
// 11. 盛最多水的容器

class Solution {
public:
    int maxArea(vector<int> &height) {

        //  单调性
        //  v = h * w

        int left = 0, right = height.size() - 1, ret = 0;
        while (left < right) {
            int v = min(height[left], height[right]) * (right - left); //主要看小的高度
            ret = max(ret, v);
            // 移动指针
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};