//
// Created by huanyan on 2021/12/2.
//

/*
 * use the four assistant list
 * left list is used to link the smaller nodes.
 * right list is used to link the larger nodes.
 * left_head is used to store the smaller list head node, and is used to return
 * right_hed is used to store the larger list head node, and is used to link by left(it is the tail of smaller list)
 */

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *left = new ListNode(), *left_head = left, *right = new ListNode(), *right_head = right;

        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = nullptr;
        left->next = right_head->next;
        return left_head->next;
    }
};