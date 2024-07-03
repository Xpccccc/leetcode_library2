
// https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
// 673. 最长递增子序列的个数

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // len[i] -- 以i为结尾的最长严格递增子序列的长度
        // count[i] -- 以i结尾的当前最长子序列长度的个数
        int n = nums.size();
        vector<int> len(n, 1), count(n, 1); // 最短长度为1

        int retlen = 1, retcount = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) { // 找到了更长的子序列
                        len[i] = len[j] + 1;
                        count[i] = count[j]; // 以j结尾的个数，因为序列加上i位置还是最长，就是在找到了这个j的位置的时候
                    } else if (len[j] + 1 == len[i]) {
                        count[i] += count[j]; // 相等个数就加加上之前的长度
                    }
                }
            }
            // 每次循环过后，对比之前的最长长度，相等就加上现在的长度
            if (retlen == len[i])
                retcount += count[i];
            else if (retlen < len[i]) { // 大于就重新开始
                retlen = len[i];
                retcount = count[i];
            }
        }
        return retcount;
    }
};