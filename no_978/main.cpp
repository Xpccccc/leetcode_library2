
// https://leetcode.cn/problems/longest-turbulent-subarray/
// 978. 最长湍流子数组

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // dp[i] -- 以i为结尾的最大湍流子数组的长度
        // f[i]  --  当前以i位置为结尾，i位置呈现上升趋势的最大湍流子数组的长度
        // g[i]  --  当前以i位置为结尾，i位置呈现下降趋势的最大湍流子数组的长度
        int n = arr.size();
        if (n == 1)
            return 1;
        vector<int> f(n, 1), g(n, 1); // 初始化全1，因为只有一个元素的湍流数组长度为1，后面就不用判断去初始化了
        int maxlen = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1])
                f[i] = g[i - 1] + 1;
            else if (arr[i] > arr[i - 1])
                g[i] = f[i - 1] + 1;
            maxlen = max(maxlen, max(f[i], g[i]));
        }
        return maxlen;
    }
};