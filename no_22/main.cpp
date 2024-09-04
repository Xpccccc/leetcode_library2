
// https://leetcode.cn/problems/generate-parentheses/
// 22. 括号生成

class Solution {

    int n;         // 括号对数
    int left = 0;  // 左括号数
    int right = 0; // 右括号数
    string path;
    vector<string> ret;

public:
    vector<string> generateParenthesis(int num) {
        // 左括号数量 == 右括号数量
        // 子串中 左括号数量 >= 右括号数量
        n = num;
        dfs();
        return ret;
    }

    void dfs() {
        if (right == n) {
            ret.push_back(path);
            return;
        }

        // 添加左括号
        if (left < n) { // left从0开始，所以小于n就是n次
            path.push_back('(');
            left++;
            dfs();
            path.pop_back();
            left--; // 恢复现场
        }

        // 添加右括号
        if (right < left) { // left == right ,下面再加)就会右超左
            path.push_back(')');
            right++;
            dfs();
            path.pop_back();
            right--; // 恢复现场
        }
    }
};