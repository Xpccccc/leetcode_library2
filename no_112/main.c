
//112. 路径总和
//题目链接https://leetcode.cn/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode *root, int sum) {
    if (!root) return false;
    sum = sum - root->val;
    // 左右节点均为 NULL ，且 sum 为 0 时, 满足条件
    if (!root->left && !root->right && !sum) return true;
    //去左右子树继续找路径
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}