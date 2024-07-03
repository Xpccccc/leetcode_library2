
// https://leetcode.cn/problems/last-stone-weight-ii/
// 1049. 最后一块石头的重量 II

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // dp[i][j] -- 从前i个数中随机选到总和不超过j的最大和
        int n = stones.size();
        int sum = 0;
        for (auto e : stones)
            sum += e;
        int a = sum / 2;
        // 优化
        vector<int> dp(a + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = a; j >= stones[i - 1]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * dp[a];
    }
};

// class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        // dp[i][j] -- 从前i个数中随机选到总和不超过j的最大和
//        int n = stones.size();
//        int sum = 0;
//        for (auto e : stones)
//            sum += e;
//        int a = sum / 2;
//        vector<vector<int>> dp(n + 1, vector<int>(a + 1));
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= a; ++j) { // 也可以j从0开始，因为这里stones不存在0
//                dp[i][j] = dp[i - 1][j];
//                if (j >= stones[i - 1])
//                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] +
//                                                 stones[i - 1]);
//            }
//        }
//        return sum - 2 * dp[n][a];
//    }
//};