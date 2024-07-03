
// https://leetcode.cn/problems/duplicate-zeros/
// 1089. 复写零
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int dest = -1, cur = 0;
        int n = arr.size();
        // 先找到最后要复写的位置
        // 按照从前往后cur++的思想，cur遇到1,dest++,cur遇到0，dest +=
        // 2,就能找到最后一个要复写的元素

        while (dest < (n - 1)) {
            if (arr[cur])
                dest++;
            else
                dest += 2;
            if (dest != n - 1 && dest != n) // dest到最终位置了，cur不用++
                cur++;
        }


        // 特殊情况 dest = n,则直接把n-1位置填0就行
        if (dest == n) {
            arr[dest - 1] = 0;
            cur--;
            dest -= 2;
        }
        while (cur >= 0) {
            // cur 不为0，则填到dest位置
            if (arr[cur]) {
                arr[dest] = arr[cur];

            } else {
                // cur 为0 ，dest位置填0，并且前面一个位置也填0
                arr[dest--] = 0;
                arr[dest] = 0;
            }
            --cur;
            --dest;
        }
    }
};