//
// Created by huanyan on 2021/12/14.
//

class Solution {
public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector <vector<int>> answer;
        queue < TreeNode * > q;
        q.push(root);
        int flag = false;

        while (!q.empty()) {
            deque<int> path;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front();
                q.pop();

                if (flag) {
                    path.push_front(node->val);
                } else {
                    path.push_back(node->val);
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            flag = !flag;
            answer.push_back(vector < int > {path.begin(), path.end()});
        }

        return answer;
    }
};