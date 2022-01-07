//
// Created by huanyan on 2021/12/20.
//

class Solution {
public:
    void flatten(TreeNode *root) {
        vector < TreeNode * > preorder;
        stack < TreeNode * > mono_stack;
        TreeNode *node = root;

        while (node != nullptr || !mono_stack.empty()) {
            while (node != nullptr) {
                preorder.push_back(node);
                mono_stack.push(node);
                node = node->left;
            }

            node = mono_stack.top();
            mono_stack.top();

            node = node->right;
        }

        for (int i = 1; i < preorder.size(); i++) {
            auto pre = preorder[i - 1], curr = preorder[i];
            pre->left = nullptr;
            pre->right = curr;
        }
    }

    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        stack < TreeNode * > mono_stack;
        mono_stack.push(root);
        TreeNode *pre = nullptr;

        while (!mono_stack.empty()) {
            auto node = mono_stack.top();
            mono_stack.pop();

            if (pre != nullptr) {
                pre->left = nullptr;
                pre->right = node;
            }

            if (node->right != nullptr) {
                mono_stack.push(node->right);
            }
            if (node->left != nullptr) {
                mono_stack.push(node->left);
            }

            pre = node;
        }
    }

    void flatten(TreeNode *root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left, last_r = next;
                while (last_r->right != nullptr) {
                    last_r = last_r->right;
                }
                last_r->right = curr->right;
                curr->right = next;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};