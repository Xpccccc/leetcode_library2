
//145. 二叉树的后序遍历
//题目链接https://leetcode.cn/problems/binary-tree-postorder-traversal/

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

void postOrder(int *arr, struct TreeNode *root, int *returnSize) {//后序遍历，左右中
    if (!root)
        return;
    postOrder(arr, root->left, returnSize);
    postOrder(arr, root->right, returnSize);
    arr[(*returnSize)++] = root->val;
}


int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 100);
    *returnSize = 0;
    postOrder(arr, root, returnSize);
    return arr;
}