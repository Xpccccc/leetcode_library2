

//205. 同构字符串
//题目链接https://leetcode.cn/problems/isomorphic-strings/

#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char *s, char *t) {
    int arr[127] = {0};//arr的元素为零说明第一次出现对应关系
    for (int i = 0; i < 127; i++) {
        arr[i] = -1;//防止初始化为0的误会
    }
    //如果字符是第一次出现，则其对应的字符映射肯定是对的
    for (int i = 0; i < strlen(s); i++) {
        //字符对应ascii码的值
        if (arr[(int) s[i]] == -1) {
            //第一次出现字符对应关系
            arr[(int) s[i]] = (int) t[i];//表示出现过一次了，确定好对应关系了
        } else if (arr[(int) s[i]] != -1) {
            if ((char) (arr[(int) s[i]]) != t[i]) {
                return false;//不是之前的对应关系
            }
        }
    }
    //继续判断不同字符不能映射到同一字符上
    //检查arr的除了-1外，有没有相同值的元素
    for (int i = 0; i < 127; i++) {
        for (int j = i + 1; j < 127; j++) {
            if (arr[i] == arr[j] && arr[i] != -1) {
                return false;//存在不同字符映射到同一个字符上
            }
        }
    }
    return true;
}

int main() {
    isIsomorphic("foo", "bar");
    return 0;
}