//
// Created by huanyan on 2021/8/10.
//

#include <iostream>
#include <leetcode/model.cpp>

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *guard = new ListNode(-1);
        ListNode *tail = guard;
        int carry = 0;
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;

            if (!l1 && l2) {
                tail->next = l2;
            } else {
                tail->next = l1;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail = tail->next;
            tail->val = sum % 10;
        }
        if (carry > 0) {
            tail->next = new ListNode(1);
        }

        return head->next;
    }
};