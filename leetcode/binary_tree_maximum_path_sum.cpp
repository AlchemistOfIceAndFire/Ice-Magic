//
// Created by huanyan on 2021/12/24.
//

class Solution {
private:
    int sum = INT_MIN;
public:
    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int l_max_sum = max(dfs(node->left), 0);
        int r_max_sum = max(dfs(node->right), 0);

        sum = max(sum, l_max_sum + r_max_sum + node->val);

        return max(l_max_sum, r_max_sum) + node->val;
    }

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return sum;
    }
};