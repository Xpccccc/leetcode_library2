
//111. 二叉树的最小深度
//题目链接https://leetcode.cn/problems/minimum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int min(int a, int b) {
    return a < b ? a : b;
}

int minDepth(struct TreeNode *root) {
    if (!root)
        return 0;
    int left_high = minDepth(root->left);
    int right_hight = minDepth(root->right);
    //后序遍历，左右中
    if (root->left == NULL && root->right != NULL)
        return 1 + right_hight;//左子树为空，右子树不空，则根据题意最小高度在右子树那边
    if (root->right == NULL && root->left != NULL)
        return 1 + left_high;
    int res = min(left_high, right_hight) + 1;//取最小高度,加1是加上跟节点高度
    return res;
}