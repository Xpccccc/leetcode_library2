
//144. 二叉树的前序遍历
//题目链接https://leetcode.cn/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preOrder(int *arr, struct TreeNode *root, int *returnSize) {//前序遍历
    if (!root)
        return;
    arr[(*returnSize)++] = root->val;
    preOrder(arr, root->left, returnSize);
    preOrder(arr, root->right, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 100);
    *returnSize = 0;
    preOrder(arr, root, returnSize);
    return arr;
}