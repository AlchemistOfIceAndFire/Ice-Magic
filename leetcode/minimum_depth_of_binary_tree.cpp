//
// Created by huanyan on 2021/12/16.
//

class Solution {
public:
    int minDepth(TreeNode *root) {
        // if node == nullptre means no additional length, return 0
        if (root == nullptr) {
            return 0;
        }

        // if left and right node both are nullptr means this is the leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // because of we need to get minimum value, so init the depth is INT_MAX
        int min_depth = INT_MAX;

        // judge left sub tree and right sub tree who are the minimum one
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
    }

    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int answer = INT_MAX, level = 0;
        queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            level++;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    answer = min(answer, level);
                    return answer;
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return answer;
    }
};