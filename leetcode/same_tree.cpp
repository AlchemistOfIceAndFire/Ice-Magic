//
// Created by huanyan on 2021/12/13.
//

class Solution {
public:
    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        return dfs(p, q);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        queue < TreeNode * > q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            p = q1.front(), q = q2.front();
            q1.pop();
            q2.pop();

            if (p->val != q->val) {
                return false;
            }

            TreeNode *p_l = p->left, *p_r = p->right, *q_l = q->left, *q_r = q->right;
            if (p_l == nullptr ^ q_l == nullptr) {
                return false;
            }
            if (p_r == nullptr ^ q_r == nullptr) {
                return false;
            }
            if (p_l != nullptr) {
                q1.push(p_l);
            }
            if (p_r != nullptr) {
                q1.push(p_r);
            }
            if (q_l != nullptr) {
                q2.push(q_l);
            }
            if (q_r != nullptr) {
                q2.push(q_r);
            }
        }
        return q1.empty() && q2.empty();
    }
};