
// https://leetcode.cn/problems/evaluate-boolean-binary-tree/
// 2331. 计算布尔二叉树的值

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr)
            return root->val == 0 ? false : true;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return root->val == 2 ? left | right : left & right;
    }
};