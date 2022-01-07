//
// Created by huanyan on 2021/12/14.
//

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth(TreeNode *root) {
        int answer = 0;
        if (root == nullptr) {
            return 0;
        }
        queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            answer++;
        }
        return answer;
    }
};