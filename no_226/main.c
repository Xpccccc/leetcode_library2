
//226. 翻转二叉树
//题目链接https://leetcode.cn/problems/invert-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void reverse(struct TreeNode *root) {
    //每次都交换根都左右节点    
    if (root) {
        struct TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }
}

struct TreeNode *invertTree(struct TreeNode *root) {
    struct TreeNode *r = root;
    reverse(root);
    return r;
}