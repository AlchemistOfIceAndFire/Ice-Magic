//
// Created by huanyan on 2021/11/30.
//

/*
 *
 * inorder -> left, root, right
 * so when we iterate the tree, we need to find the most left node firstly, and process it's root, then it's root's right.
 * when we finish this, need to process the root's root, same to previous process.
 *
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack <pair<TreeNode *, int>> mono_stack;
        mono_stack.push(make_pair(root, 0));

        while (!mono_stack.empty()) {
            auto[node, color] =mono_stack.top();
            mono_stack.pop();

            if (node == nullptr) {
                continue;
            }

            if (color == 0) {
                mono_stack.push(make_pair(node->right, 0));
                mono_stack.push(make_pair(node, 1));
                mono_stack.push(make_pair(node->left, 0));
            } else {
                answer.push_back(node->val);
            }
        }
        return answer;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack < TreeNode * > mono_stack;
        TreeNode *node = root;

        while (node != nullptr || !mono_stack.empty()) {
            // iterate node's left sub tree, to find most left node
            while (node != nullptr) {
                mono_stack.push(node);
                node = node->left;
            }

            // pop the most left unused node
            node = mono_stack.top();
            mono_stack.pop();

            answer.push_back(node->val);

            // iterate node down, need to iterate node's right sub tree
            node = node->right;
        }
        return answer;
    }
};