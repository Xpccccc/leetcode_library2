
//108. 将有序数组转换为二叉搜索树
//题目链接https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

//  Definition for a binary tree node.
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize <= 0)//当前节点的右孩子为空，或者当前节点只有一个右孩子，没有左孩子
        return NULL;
    //二分查找
    int i = 0;
    int j = numsSize-1;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = i+(j-i)/2;
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums,mid);//插入左子树
    root->right = sortedArrayToBST(nums+mid+1,numsSize-mid-1);//插入右子树
    return root;
}
