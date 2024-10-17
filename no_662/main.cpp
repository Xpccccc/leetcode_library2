
// https://leetcode.cn/problems/maximum-width-of-binary-tree/
// 662. 二叉树最大宽度

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
    int widthOfBinaryTree(TreeNode* root) {
        // 使用队列
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1}); // 节点和编号
        int maxwide = 0;
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second; // 最左边节点编号
            unsigned long long right = q.back().second; // 最右边节点编号
            maxwide = max(maxwide, (int)(right - left + 1));

            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();

                if (cur.first->left)
                    q.push({cur.first->left,
                            cur.second * 2}); // 左节点入队列和它的编号
                if (cur.first->right)
                    q.push({cur.first->right,
                            cur.second * 2 + 1}); // 右节点入队列和它的编号
            }
        }
        return maxwide;
    }
};