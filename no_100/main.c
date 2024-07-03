//100. 相同的树
//题目链接https://leetcode.cn/problems/same-tree/

#include <stdbool.h>
#include <MacTypes.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (p != NULL && q != NULL) {//如果当前两棵树指针所指向的值不空，则判断当前值是否相等，并判断当前节点的左右孩子是否相等
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else if (p == NULL && q == NULL) {
        return true;
    } else {
        return false;
    }
}
