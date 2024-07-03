
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// 438. 找到字符串中所有字母异位词

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 滑动窗口
        // 互为异位词，就字母种类和个数相等
        // 使用两个哈希表
        int hash1[26] = {0};
        int hash2[26] = {0};
        for (auto c : p)
            hash1[c - 'a']++;

        int n = s.size();
        int k = p.size();
        int effective = 0;
        int left = 0, right = 0;
        vector<int> ret;
        while (right < n) {
            // 进窗口
            hash2[s[right] - 'a']++;
            if (hash2[s[right] - 'a'] <= hash1[s[right] - 'a'])
                ++effective; // 有效字符

            // 窗口大小恒定k
            while (right - left + 1 > k) {
                // 出窗口
                if (hash2[s[left] - 'a'] <= hash1[s[left] - 'a'])
                    --effective; // 有效字符
                hash2[s[left] - 'a']--;
                ++left;
            }
            // 更新结果
            if (effective == k)
                ret.push_back(left);
            ++right;
        }
        return ret;
    }
};

// class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        // 滑动窗口
//        // 互为异位词，就字母种类和个数相等
//        // 使用两个哈希表
//        int hash1[26] = {0};
//        int hash2[26] = {0};
//        for (auto c : p)
//            hash1[c-'a']++;
//
//        int n = s.size();
//        int k = p.size();
//        int left = 0, right = 0;
//        vector<int> ret;
//        while (right < n) {
//            // 进窗口
//            hash2[s[right]-'a']++;
//            // 窗口大小恒定3
//            while (right - left + 1 > k) {
//                // 出窗口
//                hash2[s[left] - 'a']--;
//                ++left;
//            }
//            // 更新结果
//            bool flag = true;
//            for (int i = 0; i < 26; ++i) {
//                if (hash1[i] != hash2[i]) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag)
//                ret.push_back(left);
//            ++right;
//        }
//        return ret;
//    }
//};