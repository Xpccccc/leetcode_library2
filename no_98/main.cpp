
// https://leetcode.cn/problems/validate-binary-search-tree/
// 98. 验证二叉搜索树

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
    long preNum = LONG_MIN;

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        // 剪枝
        if (left == false)
            return false;
        bool cur = false;
        if (root->val > preNum)
            cur = true;
        // 剪枝
        if (cur == false)
            return false;
        preNum = root->val;
        bool right = isValidBST(root->right);
        return left && cur && right;
    }
};