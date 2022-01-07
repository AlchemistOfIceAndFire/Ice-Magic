//
// Created by huanyan on 2021/12/16.
//

class Solution {
public:
    bool goThrough(TreeNode *node, int targetSum) {
        if (node == nullptr) {
            return false;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return targetSum == node->val;
        }
        return goThrough(node->left, targetSum - node->val) || goThrough(node->right, targetSum - node->val);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        return goThrough(root, targetSum);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        queue < TreeNode * > node_q;
        queue<int> val_q;
        node_q.push(root);
        val_q.push(root->val);

        while (!node_q.empty()) {
            TreeNode *node = node_q.front();
            node_q.pop();

            int val = val_q.front();
            val_q.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (targetSum == val) {
                    return true;
                }
                continue;
            }

            if (node->left != nullptr) {
                node_q.push(node->left);
                val_q.push(val + node->left->val);
            }
            if (node->right != nullptr) {
                node_q.push(node->right);
                val_q.push(val + node->right->val);
            }
        }
        return false;
    }
};