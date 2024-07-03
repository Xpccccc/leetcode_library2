
// https://leetcode.cn/problems/missing-number/
// 268. 丢失的数字

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = (1 + nums.size()) * nums.size() / 2;
        for (auto e : nums)
            ret -= e;
        return ret;
    }
};

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int ret = (1 + nums.size()) * nums.size() / 2;
//        for (auto e : nums)
//            ret -= e;
//        return ret;
//    }
//};