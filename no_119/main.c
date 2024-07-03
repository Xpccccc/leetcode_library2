
//119. 杨辉三角 II
//题目链接：https://leetcode.cn/problems/pascals-triangle-ii/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *getRow(int rowIndex, int *returnSize) { //returnSize 代表传出数组的长度
    *returnSize = rowIndex + 1; //为returnSize赋值
    //由于返回是数组，故需要创建一个数组
    int *ret[rowIndex + 1];
    //循环遍历
    for (int i = 0; i <= rowIndex; i++) {
        //为每一行申请空间
        ret[i] = malloc(sizeof(int) * (i + 1));
        //每一行中首元素和尾元素为1
        ret[i][0] = ret[i][i] = 1;

        //循环为每一行其余元素赋值
        for (int j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }

    return ret[rowIndex]; //返回对应rowIndex行
}
