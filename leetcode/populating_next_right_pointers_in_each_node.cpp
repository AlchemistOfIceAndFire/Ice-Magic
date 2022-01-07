//
// Created by huanyan on 2021/12/22.
//

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }

        auto *left_most = root;
        while (left_most->left != nullptr) {
            auto node = left_most;

            while (node != nullptr) {
                node->left->next = node->right;

                if (node->next != nullptr) {
                    node->right->next = node->next->left;
                }

                node = node->next;
            }
            left_most = left_most->left;
        }

        return root;
    }
};