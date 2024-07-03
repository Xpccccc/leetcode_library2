
// https://leetcode.cn/problems/fruit-into-baskets/
// 904. 水果成篮

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //  滑动窗口
        int n = fruits.size();
        int hash[100001] = {0};
        int left = 0, right = 0;
        int ret = 1;
        int kinds = 0;
        while (right < n) {
            // 进窗口
            // 统计种类
            if (hash[fruits[right]] == 0) {
                ++kinds;
            }
            hash[fruits[right]]++;

            while (kinds > 2) {
                // 出窗口
                hash[fruits[left]]--;
                if(hash[fruits[left]] == 0) // 种类少了
                    --kinds;
                ++left;
            }
            // 更新结果
            ret = max(ret, right - left + 1);
            ++right;
        }
        return ret;
    }
};