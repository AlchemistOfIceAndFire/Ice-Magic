//
// Created by huanyan on 2021/12/14.
//

class Solution {
public:
    vector <vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector <vector<int>> answer;
        queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            vector<int> path;
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

                path.push_back(node->val);
            }
            answer.push_back(path);
        }
        return answer;
    }
};