//
// Created by huanyan on 2021/12/16.
//

class Solution {
public:
    void dfs(vector <vector<int>> &answer, vector<int> &path, TreeNode *node, int sum) {
        if (node == nullptr) {
            return;
        }

        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && sum == node->val) {
            answer.push_back(path);
        }

        dfs(answer, path, node->left, sum - node->val);
        dfs(answer, path, node->right, sum - node->val);

        path.pop_back();

    }

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector <vector<int>> answer;
        vector<int> path;

        dfs(answer, path, root, targetSum);
        return answer;
    }

    void buildPath(vector <vector<int>> &answer, map<TreeNode *, TreeNode *> &parents, TreeNode *node) {
        vector<int> path;
        while (node != nullptr) {
            path.push_back(node->val);
            node = parents[node];
        }
        reverse(path.begin(), path.end());
        answer.push_back(path);
    }

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        vector <vector<int>> answer;

        queue < TreeNode * > node_q;
        queue<int> val_q;
        map < TreeNode * , TreeNode * > parents;

        node_q.push(root);
        val_q.push(root->val);

        while (!node_q.empty()) {
            TreeNode *node = node_q.front();
            node_q.pop();

            int val = val_q.front();
            val_q.pop();

            if (node->left == nullptr && node->right == nullptr && val == targetSum) {
                buildPath(answer, parents, node);
            }

            if (node->left != nullptr) {
                parents[node->left] = node;
                node_q.push(node->left);
                val_q.push(val + node->left->val);
            }

            if (node->right != nullptr) {
                parents[node->right] = node;
                node_q.push(node->right);
                val_q.push(val + node->right->val);
            }
        }
        return answer;
    }
};