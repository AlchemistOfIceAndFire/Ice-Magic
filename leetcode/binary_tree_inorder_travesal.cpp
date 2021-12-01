//
// Created by huanyan on 2021/11/30.
//

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack<pair<TreeNode *, int>> mono_stack;
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
};