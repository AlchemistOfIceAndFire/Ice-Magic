//
// Created by huanyan on 2021/8/10.
//

/*
 *
 * if match:
 *    path.push
 *    visited = true
 * else:
 *    return
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <leetcode/model.cpp>
#include <math.h>
#include <stack>
#include <alloca.h>
#include <string.h>
#include <bitset>

using namespace std;

TreeNode *clone(TreeNode *node) {
    if (node == nullptr) {
        return node;
    }
    return new TreeNode(node->val, node->left, node->right);
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> answer;
    if (n == 0) {
        return answer;
    }

    answer.push_back(nullptr);
    for (int i = 1; i <= n; i++) {
        vector<TreeNode *> nodes;
        for (auto &exist: answer) {
            TreeNode *node = new TreeNode(i);
            node->left = exist;
            nodes.push_back(node);

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

int main() {

}



