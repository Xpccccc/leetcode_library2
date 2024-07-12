
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/
// 1419. 数青蛙

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string str = "croak";
        int n = str.size();
        vector<int> hash(n); // 存croak的个数
        unordered_map<char, int> ump;
        for (int i = 0; i < n; ++i) {
            ump[str[i]] = i;
        }
        for (int i = 0; i < croakOfFrogs.size(); ++i) {
            if (croakOfFrogs[i] ==
                'c') { // 看k等不等于0，不等于0则可以用之前的青蛙来叫
                if (hash[ump['k']]) {
                    --hash[ump['k']];
                }
                ++hash[ump['c']]; //
            } else {
                if (!hash[ump[croakOfFrogs[i]] - 1]) { // 前面字符不存在
                    return -1;
                } else {
                    ++hash[ump[croakOfFrogs[i]]];
                    --hash[ump[croakOfFrogs[i]] - 1];
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (hash[i])
                return -1;
        }
        return hash[n - 1];
    }
};