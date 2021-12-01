//
// Created by huanyan on 2021/11/29.
//

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *guard = new ListNode();
        guard->next = head;

        ListNode *l = guard, *r = guard->next;
        while (r != nullptr) {
            while (r->next != nullptr && r->val == r->next->val) {
                r = r->next;
            }

            if (l->next == r) {
                l = l->next;
            } else {
                l->next = r->next;
            }

            r = r->next;
        }
        return guard->next;
    }
};