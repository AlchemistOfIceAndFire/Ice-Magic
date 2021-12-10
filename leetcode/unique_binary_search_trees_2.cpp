//
// Created by huanyan on 2021/12/10.
//

class Solution {
public:
    vector<TreeNode *> dfs(int begin, int end) {
        if (begin > end) {
            return {nullptr};
        }

        vector < TreeNode * > answer;
        for (int i = begin; i <= end; i++) {
            vector < TreeNode * > l_trees = dfs(begin, i - 1);
            vector < TreeNode * > r_trees = dfs(i + 1, end);

            for (auto l_tree: l_trees) {
                for (auto &r_tree: r_trees) {
                    TreeNode *node = new TreeNode(i, l_tree, r_tree);
                    answer.push_back(node);
                }
            }
        }
        return answer;
    }

    vector<TreeNode *> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return dfs(1, n);
    }

    TreeNode *clone(TreeNode *node) {
        if (node == nullptr) {
            return node;
        }
        return new TreeNode(node->val, clone(node->left), clone(node->right));
    }

    vector<TreeNode *> generateTrees(int n) {
        vector < TreeNode * > answer;
        if (n == 0) {
            return answer;
        }

        answer.push_back(nullptr);
        // iterate each value to be a root node
        for (int i = 1; i <= n; i++) {
            vector < TreeNode * > nodes;
            // iterate each generated tree to insert new node i
            for (auto &exist: answer) {
                // use the i to root node, and it's val more than each generated trees node val, so previously generated is the left tree for new node i
                TreeNode *node = new TreeNode(i);
                node->left = exist;
                nodes.push_back(node);

                // insert the node i to previously generated tree, but not being a root node, so it need to insert to this tree each right position
                for (int j = 0; j <= n; j++) {
                    node = clone(exist);
                    TreeNode *_node = node;

                    for (int k = 0; k < j; k++) {
                        if (_node == nullptr) {
                            break;
                        }
                        _node = _node->right;
                    }

                    if (_node == nullptr) {
                        break;
                    }

                    TreeNode *r_node = _node->right;
                    TreeNode *insert = new TreeNode(i, r_node, nullptr);
                    _node->right = insert;
                    nodes.push_back(node);
                }
            }
            answer = nodes;
        }

        return answer;
    }
};