//
// Created by huanyan on 2021/12/14.
//

class Solution {
public:
    bool dfs(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr ^ right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return dfs(root->left, root->right);
    }

    bool isSymmetric(TreeNode *root) {
        queue < TreeNode * > q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()) {
            TreeNode *l = q1.front(), *r = q2.front();
            q1.pop();
            q2.pop();

            if (l == nullptr && r == nullptr) {
                continue;
            }
            if (l == nullptr ^ r == nullptr) {
                return false;
            }
            if (l->val != r->val) {
                return false;
            }

            q1.push(l->left);
            q1.push(l->right);
            q2.push(r->right);
            q2.push(r->left);
        }
        return q1.empty() && q2.empty();
    }
};