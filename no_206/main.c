
//206. 反转链表
//题目链接https://leetcode.cn/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *reverseList(struct ListNode *head) {
    if (!head)
        return head;
    //先创建一个头结点
    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = NULL;
    //采用头插法
    struct ListNode *p = head;
    struct ListNode *r = p;
    while (p) {
        r = p->next;//防止断链
        p->next = list->next;
        list->next = p;
        p = r;
    }
    return list->next;
}