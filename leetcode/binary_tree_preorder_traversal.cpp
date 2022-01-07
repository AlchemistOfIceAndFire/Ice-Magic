//
// Created by huanyan on 2021/12/14.
//

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack < TreeNode * > mono_stack;
        TreeNode *node = root;

        while (node != nullptr || !mono_stack.empty()) {
            while (node != nullptr) {
                answer.push_back(node->val);
                mono_stack.push(node);
                node = node->left;
            }

            node = mono_stack.top();
            mono_stack.pop();

            node = node->right;
        }
        return answer;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> answer;
        stack < TreeNode * > mono_stack;
        mono_stack.push(root);

        while (!mono_stack.empty()) {
            auto node = mono_stack.top();
            mono_stack.pop();

            answer.push_back(node->val);

            if (node->right != nullptr) {
                mono_stack.push(node->right);
            }

            if (node->left != nullptr) {
                mono_stack.push(node->left);
            }
        }
        return answer;
    }
};