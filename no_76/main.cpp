//
// https://leetcode.cn/problems/minimum-window-substring/
// 76. 最小覆盖子串


class Solution {
public:
    string minWindow(string s, string t) {

        // 滑动窗口
        if (t.size() > s.size())
            return "";
        int hash1[58] = {0}; // 存t字母
        int tkinds = 0;
        for (auto c: t) {
            if (hash1[c - 'A'] == 0)
                tkinds++;
            hash1[c - 'A']++;
        }

        int hash2[58] = {0}; // 存s当前符合要求的时候已经进入hash的字母
        int left = 0, right = 0;
        int n = s.size();
        int skinds = 0;
        int retstart = 0, retlen = 100001;
        while (right < n) {
            // 进窗口
            hash2[s[right] - 'A']++;
            // 进窗口后统计种类
            // 保证该字符是有效的，且该字符个数等于t对应字符
            // 如果是大于等于，会重复++，例子ABBCA，ABC，在right到第二个B的时候种类变为3了，正确应该是2
            if (hash1[s[right] - 'A'] != 0 &&
                hash2[s[right] - 'A'] == hash1[s[right] - 'A'])
                skinds++;
            while (skinds == tkinds) {
                // 更新结果
                if (right - left + 1 < retlen) {
                    retstart = left;
                    retlen = right - left + 1;
                }

                // 出窗口前统计种类
                // 出窗口前必须保证个数相等才--种类
                // 也能出窗口后，个数小于才--种类，因为出窗口前个数肯定是大于等于了
                if (hash1[s[left] - 'A'] != 0 &&
                    hash2[s[left] - 'A'] ==
                    hash1[s[left] - 'A']) // 保证该字符是有效的
                    --skinds;
                // 出窗口
                hash2[s[left] - 'A']--;

                // // 也能出窗口后，个数小于才--种类，因为出窗口前个数肯定是大于等于了
                // if (hash1[s[left] - 'A'] != 0 &&
                //     hash2[s[left] - 'A'] <
                //     hash1[s[left] - 'A']) // 保证该字符是有效的
                //     --skinds;
                
                ++left;
            }
            ++right;
        }
        if (retlen == 100001)
            return "";
        else
            return s.substr(retstart, retlen);
    }
};