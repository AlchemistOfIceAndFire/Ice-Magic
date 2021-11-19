//
// Created by huanyan on 2021/11/11.
//

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        int n = 1;
        ListNode *tail = head;
        while (tail->next != nullptr) {
            n = n + 1;
            tail = tail->next;
        }

        int idx = n - k % n;
        if (idx == n) {
            return head;
        }

        // find kth node from the end
        ListNode *current = head;
        for (int i = 0; i < idx - 1; i++) {
            current = current->next;
        }

        ListNode *answer = current->next;
        current->next = nullptr;
        tail->next = head;
        return answer;
    }
};