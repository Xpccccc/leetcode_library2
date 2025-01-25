
// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
// 2208. 将数组和减半的最少操作次数

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap;
        double sum = 0;
        for (auto e : nums) {
            heap.push(e);
            sum += e;
        }
        sum /= 2.0;
        int count = 0;
        while (sum > 0) {
            double t = heap.top() / 2;
            heap.pop();
            sum -= t;
            count++;
            heap.push(t);
        }
        return count;
    }
};