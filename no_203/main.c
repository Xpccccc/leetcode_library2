
//203. 移除链表元素
//题目链接https://leetcode.cn/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *removeElements(struct ListNode *head, int val) {
    if (!head)
        return head;
    //给链表加上头节点
    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *p = list;//记录要删除的元素的前驱
    struct ListNode *q = list->next;//记录要删除的元素
    while (q) {
        if (q->val == val) {
            p->next = q->next;//删除值为val的元素
            q = q->next;
        } else {
            p = p->next;//同步后移
            q = q->next;
        }
    }
    return list->next;
}