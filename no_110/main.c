#include <stdbool.h>
#include <MacTypes.h>
#include <stdlib.h>

//110. 平衡二叉树
//题目链接https://leetcode.cn/problems/balanced-binary-tree/
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

//104.求深度的算法
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


bool isBalanced(struct TreeNode *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))//根为空或者子树到了叶子节点
        return true;
    // 计算当前节点的左右子树的高度差
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)//存在平衡因子大于1的节点
        return false;
    return isBalanced(root->left) && isBalanced(root->right);//继续向下查找，左右子树都平衡即都返回true，则返回true
}