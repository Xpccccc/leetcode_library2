#include <stdlib.h>

//118. 杨辉三角
//题目链接https://leetcode.cn/problems/pascals-triangle/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    int i, j;
    //开辟返回的指针数组空间
    int **ret = (int **) malloc(sizeof(int *) * numRows);
    //返回杨辉三角的行数
    *returnSize = numRows;
    //开辟分配杨辉三角中每一列的空间
    *returnColumnSizes = (int *) malloc(sizeof(int) * numRows);//返回后遍历使用
    for (i = 0; i < numRows; i++) {
        //开辟杨辉三角中每一行的具体空间
        ret[i] = (int *) malloc(sizeof(int) * (i + 1));
        //开辟分配杨辉三角中每一行的列数
        (*returnColumnSizes)[i] = i + 1;//返回后遍历使用
        //将每行的头尾元素置为1
        ret[i][0] = ret[i][i] = 1;
        //构造元素
        for (j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;
}