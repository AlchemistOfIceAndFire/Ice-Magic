//
// Created by huanyan on 2021/11/29.
//

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *l = head, *r = head->next;
        while (r != nullptr) {
            if (l->val == r->val) {
                r = r->next;
                l->next = r;
            } else {
                l = r;
                r = r->next;
            }
        }
        return head;
    }
};