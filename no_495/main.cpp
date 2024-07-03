
// https://leetcode.cn/problems/teemo-attacking/
// 495. 提莫攻击

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            int x = timeSeries[i + 1] - timeSeries[i];
            if (x >= duration)
                ret += duration;
            else
                ret += x;
        }
        return ret + duration;
    }
};