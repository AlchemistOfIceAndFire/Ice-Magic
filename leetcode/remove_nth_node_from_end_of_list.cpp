//
// Created by huanyan on 2021/8/24.
//

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *guard = new ListNode(0, head);
        ListNode *l = guard, *r = guard;

        for (int i = 0; i < n; i++) {
            r = r->next;
        }

        while (r->next != nullptr) {
            l = l->next;
            r = r->next;
        }

        l->next = l->next->next;

        return guard->next;
    }
};