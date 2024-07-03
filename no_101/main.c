#include <stdbool.h>
#include <MacTypes.h>

//101. 对称二叉树
//题目链接https://leetcode.cn/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool compare(struct TreeNode *p, struct TreeNode *q) {
    if (p != NULL && q != NULL) {//左右指向的节点都不空
        if (p->val != q->val) {//当前所指向的值不相等
            return false;
        }
            //当前所指向的值相等，继续判断左右子树相反方向指针
        else if (compare(p->left, q->right) == false) {
            return false;
        } else if (compare(p->right, q->left) == false) {
            return false;
        } else {
            return true;
        }
    } else if (p == NULL && q == NULL) {//左右指向的节点都空
        return true;
    } else {
        return false;//左右指向的节点一个空一个不空
    }
}

bool isSymmetric(struct TreeNode *root) {
    return compare(root->left, root->right);
}