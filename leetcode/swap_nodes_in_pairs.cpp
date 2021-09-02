//
// Created by huanyan on 2021/8/31.
//

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *guard = new ListNode();
        ListNode *tail = guard;
        ListNode *l = head, *r = head->next;

        while (r != nullptr) {
            //swap
            tail->next = r;
            l->next = r->next;
            r->next = l;

            // move tail, l, r
            tail = l;
            l = l->next;
            r = l == nullptr ? nullptr : l->next;
        }
        return guard->next;
    }

    ListNode *swapPairs(ListNode *head) {
        ListNode *guard = new(ListNode, head);
        ListNode *current = guard;

        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode *l = current->next;
            ListNode *r = current->next->next;

            //swap
            current->next = r;
            l->next = r->next;
            r->next = l;

            //move
            current = l;
        }
        return guard->next;
    }

    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
