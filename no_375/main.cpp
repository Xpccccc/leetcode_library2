
// https://leetcode.cn/problems/guess-number-higher-or-lower-ii/
// 375. 猜数字大小 II

class Solution {
    int memo[201][201];

public:
    int getMoneyAmount(int n) { return dfs(1, n); }

    int dfs(int left, int right) {
        if (left >= right)
            return 0;
        if (memo[left][right])
            return memo[left][right];
        int ret = INT_MAX;
        for (int head = left; head <= right; ++head) {
            int x = dfs(left, head - 1);
            int y = dfs(head + 1, right);

            // head + max(x, y)取最大
            ret = min(ret, head + max(x, y));// 取当前以head为根的里面最大的里面的最小的
        }
        memo[left][right] = ret;
        return ret;
    }
};