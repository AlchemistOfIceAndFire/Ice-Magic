//
// Created by huanyan on 2021/12/13.
//

class Solution {
public:
    bool dfs(TreeNode *root, long lower, long upper) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        // if turn to left branch, set the upper.
        // if turn to right branch, set the lower.
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) {
        return dfs(root, INT64_MIN, INT64_MAX);
    }

    bool isValidBST(TreeNode *root) {
        long pre_val = INT64_MIN;
        stack <pair<TreeNode *, int>> mono_stack;
        mono_stack.push(make_pair(root, 0));

        while (!mono_stack.empty()) {
            auto[node, color] = mono_stack.top();
            mono_stack.pop();

            if (node == nullptr) {
                continue;
            }

            if (color == 0) {
                mono_stack.push(make_pair(node->right, 0));
                mono_stack.push(make_pair(node, 1));
                mono_stack.push(make_pair(node->left, 0));
            } else {
                if (node->val <= pre_val) {
                    return false;
                }
                pre_val = node->val;
            }
        }
        return true;
    }
};