
// https://leetcode.cn/problems/swap-nodes-in-pairs/
//  24. 两两交换链表中的节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto tmp = swapPairs(head->next->next); // 返回后面的链表的第一个节点
        auto ret = head->next;
        head->next->next = head; 
        head->next = tmp;
        return ret;
    }
};