//
// Created by huanyan on 2021/12/15.
//

class Solution {
public:
    vector <vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector <vector<int>> answer;
        stack <vector<int>> mono_stack;
        queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            vector<int> path;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();

                path.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            mono_stack.push(path);
        }

        while (!mono_stack.empty()) {
            answer.push_back(mono_stack.top());
            mono_stack.pop();
        }
        return answer;
    }
};