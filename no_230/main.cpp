
// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
// 230. 二叉搜索树中第 K 小的元素

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
    int count;
    int ret;

public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr || count == 0)
            return;
        dfs(root->left);
        count--;
        if (count == 0)
            ret = root->val;
        dfs(root->right);
    }
};