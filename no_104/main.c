#include <MacTypes.h>


//104. 二叉树的最大深度
//题目链接https://leetcode.cn/problems/maximum-depth-of-binary-tree/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    if (!root->left)//如果左子树为空，检查右子树
        return maxDepth(root->right) + 1;
    if (!root->right)//如果右子树为空，检查左子树
        return maxDepth(root->left) + 1;
    //如果左右子树都不空，选更深的子树
    return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}