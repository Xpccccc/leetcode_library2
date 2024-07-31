
// https://leetcode.cn/problems/merge-two-sorted-lists/
// 21. 合并两个有序链表

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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;
            if (list1->val <= list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
};


//#include <MacTypes.h>
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//
//// 21. 合并两个有序链表
//struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//    struct ListNode *h = (struct ListNode *) malloc(sizeof(struct ListNode));//创建一个新表头
//    struct ListNode *r = h;//h尾指针指向h的最后一个元素
//    h->next = NULL;
//    while (list1 && list2) {
//        if (list1->val <= list2->val) {
//            //指向list1当前节点
//            r->next = list1;
//            r = r->next;//h尾指针指向h的最后一个元素
//            list1 = list1->next;
//        } else {
//            //指向list2当前节点
//            r->next = list2;
//            r = r->next;//h尾指针指向h的最后一个元素
//            list2 = list2->next;
//        }
//    }
//    if (list2) {//list2不空
//        r->next = list2;
//    }
//    if (list1) {//list1不空
//        r->next = list1;
//    }
//    return h->next;
//}