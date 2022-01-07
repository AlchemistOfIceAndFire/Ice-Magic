//
// Created by huanyan on 2021/12/16.
//

class Solution {
public:
    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return max(dfs(node->left), dfs(node->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root -> right);
    }

    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int l_height = dfs(node->left);
        int r_height = dfs(node->right);

        if (l_height == -1 || r_height == -1 || abs(l_height - r_height) > 1) {
            return -1;
        } else {
            return max(l_height, r_height) + 1;
        }
    }

    bool isBalanced(TreeNode *root) {
        return dfs(root) >= 0;
    }
};