//
// Created by huanyan on 2021/12/9.
//

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *guard = new ListNode(0, head);

        // find the l_tail node represent the end of left part of non-reversed list
        ListNode *l_tail = guard;
        for (int i = 0; i < left - 1; i++) {
            l_tail = l_tail->next;
        }

        // find the reversed list tail
        ListNode *r_node = l_tail;
        for (int i = 0; i < right - left + 1; i++) {
            r_node = r_node->next;
        }

        // find the reversed list head, and the begin of right part of non-reversed list
        ListNode *l_node = l_tail->next;
        ListNode *r_head = r_node->next;

        // cut down the left and right non-reversed list
        l_tail->next = nullptr;
        r_node->next = nullptr;

        // reverse the list
        ListNode *pre = nullptr;
        ListNode *cur = l_node;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // link the multiple part of list
        l_tail->next = r_node;
        l_node->next = r_head;
        return guard->next;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *guard = new ListNode(0, head);

        ListNode *pre = guard;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        /* the main idea:
         * 1. find the left_tail, reversed_left_node, changed count
         * 2. each iteration, put the current's next node to the left part that is linked by the left_tail
         */
        ListNode *cur = pre->next;
        ListNode *next = new ListNode();
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return guard->next;
    }
};