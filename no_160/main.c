

//160. 相交链表
//题目链接https://leetcode.cn/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //先求两个链表长度
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    int lenA = 0;
    int lenB = 0;
    while (pA) {//求链表A的长度
        pA = pA->next;
        lenA++;
    }
    while (pB) {//求链表B的长度
        pB = pB->next;
        lenB++;
    }
    pA = headA;//重置指针
    pB = headB;
    if (lenA >= lenB) {//链表A比链表B长，则链表A先走
        int len = lenA - lenB;
        while (len--) {
            pA = pA->next;
        }
        while (pA && pB) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
    } else {//链表B比链表A长，则链表A先走
        int len = lenB - lenA;
        while (len--) {
            pB = pB->next;
        }
        while (pA && pB) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
    }
    return NULL;
}