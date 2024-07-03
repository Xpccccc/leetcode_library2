
//141. 环形链表
//题目链接https://leetcode.cn/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if(!head)
        return false;
    //两个指针一快一慢，有环一定会重逢
    struct ListNode * fast = head;
    struct ListNode * slow = head;

    while(fast&&slow&&fast->next){
        //fast->next确保fast能访问到后两位的位置
        fast = fast->next->next;
        slow = slow->next;//fast和slow得同步后退
        if(fast == slow)
            return true;//有环
    }
    return false;//无环
}