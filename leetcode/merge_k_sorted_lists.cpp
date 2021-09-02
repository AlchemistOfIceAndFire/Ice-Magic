//
// Created by huanyan on 2021/8/31.
//

class Solution {
public:
    ListNode *conquer(ListNode *l1, ListNode *l2) {
        ListNode *guard = new ListNode();
        ListNode *tail = guard;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 == nullptr ? l2 : l1;
        return guard->next;
    }

    ListNode *divide(vector<ListNode *> &lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        }

        int mid = (begin + end) / 2;
        return conquer(divide(lists, begin, mid), divide(lists, mid + 1, end));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
};