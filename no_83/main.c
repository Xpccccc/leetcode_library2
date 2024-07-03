#include <MacTypes.h>

//83. 删除排序链表中的重复元素
//题目链接https://leetcode.cn/problems/remove-duplicates-from-sorted-list/

//Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (!head)//空链
        return NULL;
    struct ListNode *p = head;
    struct ListNode *q = p->next;
    while (q) {
        if (p->val == q->val) {
            q = q->next;
            if (!q)//如果当前q为NULLNULL，说明q前面的p的值是和q的前驱相等的，之间把p的next置空
                p->next = NULL;
        } else {
            p->next = q;
            p = q;
            q = q->next;
        }
    }
    return head;
}