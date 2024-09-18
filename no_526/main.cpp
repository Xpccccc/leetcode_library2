
// https://leetcode.cn/problems/beautiful-arrangement/
// 526. 优美的排列

class Solution {
    bool check[16];
    int ret;

public:
    int countArrangement(int n) {
        dfs(1, n);
        return ret;
    }

    void dfs(int pos, int n) {
        if (pos == n + 1) {
            ret++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (check[i] == false && (pos % i == 0 || i % pos == 0)) {
                check[i] = true;
                dfs(pos + 1, n);
                check[i] = false;
            }
        }
    }
};