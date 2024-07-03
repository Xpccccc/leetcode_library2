#include <string.h>

//58. 最后一个单词的长度
//题目链接https://leetcode.cn/problems/length-of-last-word/
int lengthOfLastWord(char * s){
    //从后往前找
    int len = strlen(s);
    int count = 0;
    for(int i=len-1; i>=0; --i){//最后一个字符'\0'不算长度
        if(s[i] != ' '){
            count++;
            if(i>=1){// 保证数组不越界
                if(s[i-1] == ' ')//如果当前字符的前一个字符是空格，则跳出循环
                    break;
            }
        }
        //是空格则往前移（for循环里的--i）      
    }
    return count;
}