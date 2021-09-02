//
// Created by huanyan on 2021/8/31.
//

class Solution {
public:
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *_tail = tail->next;
        ListNode *_head = head;

        while (tail != _tail) {
            ListNode *temp = _head->next;
            _head->next = _tail;
            _tail = _head;
            _head = temp;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *guard = new ListNode(0, head);
        ListNode *_head = guard;

        while (head != nullptr) {
            ListNode *tail = _head;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    return guard->next;
                }
            }

            ListNode *next_step_head = tail->next;
            pair < ListNode * , ListNode * > reversed = reverse(head, tail);
            _head->next = reversed.first;
            reversed.second->next = next_step_head;
            _head = reversed.second;
            head = next_step_head;
        }
        return guard->next;
    }
};
