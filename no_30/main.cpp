
// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
// 30. 串联所有单词的子串

class Solution {
public:
    vector<int> findSubstring(string s, vector <string> &words) {
        // 滑动窗口
        unordered_map<string, int> umps, umpw;
        vector<int> ret;
        for (auto &str: words)
            umpw[str]++;
        int n = s.size();
        int m = words.size();
        int wordlen = words[0].size(); // 单个单词长度
        for (int i = 0; i < wordlen; ++i) {
            int effective = 0; // 每次得重置
            int left = i, right = i;
            while (right + wordlen <= n) {
                // 进窗口
                string curright = s.substr(right, wordlen);
                umps[curright]++;
                if (umps[curright] <= umpw[curright])
                    ++effective; // 有效字符串
                while ((right - left) / wordlen + 1 > m) {
                    string curleft = s.substr(left, wordlen);
                    if (umps[curleft] <= umpw[curleft])
                        --effective; // 有效字符串
                    // 出窗口
                    umps[curleft]--;
                    left += wordlen;
                }
                // 更新结果
                if (m == effective)
                    ret.push_back(left);

                right += wordlen;
            }
            // 清空当前umps
            umps.clear();
        }
        return ret;
    }
};


//class Solution {
//public:
//    vector<int> findSubstring(string s, vector <string> &words) {
//        // 滑动窗口
//        unordered_map<string, int> umps, umpw;
//        vector<int> ret;
//        for (auto &str: words)
//            umpw[str]++;
//        int n = s.size();
//        int m = words.size();
//        int wordlen = words[0].size(); // 单个单词长度
//        for (int i = 0; i < wordlen; ++i) {
//            int left = i, right = i;
//            while (right < n) {
//                // 进窗口
//                string curright;
//                if (n - right >= wordlen) //  最后一个单词大小符合要求
//                    curright = s.substr(right, wordlen); // 越界？？
//                else
//                    break;
//                umps[curright]++;
//                while ((right - left) / wordlen + 1 > m) {
//
//                    // 出窗口
//                    string curleft = s.substr(left, wordlen);
//                    umps[curleft]--;
//                    left += wordlen;
//                }
//                // 更新结果
//                bool flag = true;
//                for (auto &e: umpw) {
//                    if (umps[e.first] != umpw[e.first]) {
//                        flag = false;
//                        break; // 相同单词个数不一样
//                    }
//                }
//                if (flag)
//                    ret.push_back(left);
//
//                right += wordlen;
//            }
//            // 清空当前umps
//            umps.clear();
//        }
//        return ret;
//    }
//};