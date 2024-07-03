//
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 3. 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口
        int hash[128]{0};
        int left = 0, right = 0, n = s.size();
        int len = 0;
        while (right < n) {
            // 进窗口
            hash[s[right]]++;
            while (
                    hash[s[right]] ==
                    2) { // 只要当前hash还有重复字符，left就得++，直到跳过重复字符
                // 出窗口
                hash[s[left]]--;
                ++left;
            }
            len = max(right - left + 1, len); // 更新结果

            ++right;
        }
        return len;
    }
};