
// https://leetcode.cn/problems/lemonade-change/
// 860. 柠檬水找零

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;// 十块和五块钱的个数
        for (auto e : bills) {
            if (e == 5)
                five++;
            else if (e == 10) {
                if (five == 0)
                    return false;
                ++ten;
                --five;
            } else {
                if (five && ten) { // 贪心
                    --ten;
                    --five;
                    // 有十块Ï先给10块
                } else if (five >= 3) {
                    five -= 3;// 找零3个五块
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};