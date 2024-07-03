//
// https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/
// LCR 173. 点名

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        // 二段性 -- 二分
        int left = 0, right = records.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid)
                left = mid + 1;
            else
                right = mid;
        }
        if(records[left] == left)
            left++;
        return left;
    }
};
