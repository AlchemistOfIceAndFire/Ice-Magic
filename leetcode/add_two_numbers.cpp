//
// Created by huanyan on 2021/8/10.
//

#include <iostream>
#include <leetcode/model.cpp>

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // generate guard node to store the head node, because in the moving period, you need to iterate the l1, l2 cause lose the head node
        ListNode *guard = new ListNode(-1);

        // generate tail node, used to store the current tail node, avoid to lose the tail node when l1 or l2 is nullptr
        ListNode *tail = guard;

        // carry is used to add 1 when pre sum >= 10
        int carry = 0;

        // avoid claim new node, jsut link the original nodes
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;

            // select next un-null node, l1 has the highest priority
            if (!l1 && l2) {
                tail->next = l2;
            } else {
                tail->next = l1;
            }

            // move the l1 and l2
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            // modify tail node val, and move it
            tail = tail->next;
            tail->val = sum % 10;
        }
        if (carry > 0) {
            tail->next = new ListNode(1);
        }

        return head->next;
    }
};