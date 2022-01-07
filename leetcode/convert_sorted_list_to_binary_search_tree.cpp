//
// Created by huanyan on 2021/12/15.
//

class Solution {
public:
    TreeNode *build(ListNode *head, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        ListNode *list_node = head;
        int mid = (l + r) / 2;
        for (int i = 0; i < mid; i++) {
            list_node = list_node->next;
        }

        TreeNode *node = new TreeNode(list_node->val);
        node->left = build(head, l, mid - 1);
        node->right = build(head, mid + 1, r);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *node = head;
        while (node != nullptr) {
            n++;
            node = node->next;
        }
        return build(head, 0, n - 1);
    }

    class Solution {
    public:
        TreeNode *build(ListNode *head, int n) {
            if (n < 0) {
                return nullptr;
            }

            ListNode *list_node = head;
            int mid = n / 2;
            for (int i = 0; i < mid; i++) {
                list_node = list_node->next;
            }

            TreeNode *node = new TreeNode(list_node->val);
            node->left = build(head, mid - 1);
            node->right = build(list_node->next, n - mid - 1);
            return node;
        }

        TreeNode *sortedListToBST(ListNode *head) {
            int n = 0;
            ListNode *node = head;
            while (node != nullptr) {
                n++;
                node = node->next;
            }
            return build(head, n - 1);
        }
    };
};