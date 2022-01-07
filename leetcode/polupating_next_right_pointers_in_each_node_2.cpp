//
// Created by huanyan on 2021/12/23.
//

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        auto left_most = root;

        while (left_most != nullptr) {
            auto node = left_most, pre = nullptr, next_left_most = nullptr;
            while (node != nullptr) {
                if (node->left != nullptr && node->right != nullptr) {
                    node->left->next = node->right;
                } else if (node->left != nullptr) {
                    auto next = node->next;
                    while (next != nullptr && (next->left == nullptr && next->right == nullptr)) {
                        next = next->next;
                    }
                    node->left->next = next == nullptr ? nullptr : next->left == nullptr ? next->right : next->left;
                }
                if (node->right != nullptr) {
                    auto next = node->next;
                    while (next != nullptr && (next->left == nullptr && next->right == nullptr)) {
                        next = next->next;
                    }
                    node->right->next = next == nullptr ? nullptr : next->left == nullptr ? next->right : next->left;
                }
                node = node->next;
            }

            while (left_most != nullptr && (left_most->left == nullptr && left_most->right == nullptr)) {
                left_most = left_most->next;
            }
            if (left_most == nullptr) {
                break;
            }
            left_most = left_most->left == nullptr ? left_most->right : left_most->left;

        }
        return root;
    }

    Node *connect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        auto left_most = root;

        while (left_most != nullptr) {
            Node *node = left_most, *pre = nullptr, *next_left_most = nullptr;
            while (node != nullptr) {
                if (node->left != nullptr) {
                    if (pre != nullptr) {
                        pre->next = node->left;
                    }

                    if (next_left_most == nullptr) {
                        next_left_most = node->left;
                    }

                    pre = node->left;
                }

                if (node->right != nullptr) {
                    if (pre != nullptr) {
                        pre->next = node->right;
                    }

                    if (next_left_most == nullptr) {
                        next_left_most = node->right;
                    }

                    pre = node->right;
                }
                node = node->next;
            }
            left_most = next_left_most;
        }
        return root;
    }

    Node *connect(Node *root) {
        if (root == nullptr){
            return root;
        }
        queue < Node * > q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();

                if (i < n - 1) {
                    node->next = q.front();
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};