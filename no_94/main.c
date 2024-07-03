#include <stdlib.h>


//94. 二叉树的中序遍历
//题目链接https://leetcode.cn/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Inorder(struct TreeNode *root, int *res, int *returnSize) {
    if (root) {//节点不为空
        Inorder(root->left, res, returnSize);
        res[(*returnSize)++] = root->val;//访问节点，存入数组，数组指针后移
        Inorder(root->right, res, returnSize);
    }
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 100);//节点数最多100
    *returnSize = 0;
    Inorder(root, res, returnSize);//中序遍历
    return res;
}
