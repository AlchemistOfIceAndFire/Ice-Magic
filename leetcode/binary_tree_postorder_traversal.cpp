//
// Created by huanyan on 2021/12/14.
//

/*
 * postorder: left, right, root
 *
 * so we can iterate the left node easily, but when we process the right node, how to know when are we processing it done, and to add the root node to answer.
 * we need to maintain a TreeNode visited_r to record the most previous right node.
 * when the current node -> right == visited_r means, we need to add the current node to answer
 *
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack < TreeNode * > mono_stack;
        TreeNode *node = root, *visited_r = nullptr;

        while (node != nullptr || !mono_stack.empty()) {
            // find the most left
            while (node != nullptr) {
                mono_stack.push(node);
                node = node->left;
            }

            // set the current processing node to node ptr
            node = mono_stack.top();
            // current node have no right node or node's right have been processed
            // if this case, we need to process current node, and return to upper level, so we need to set node to nullptr, and pop this current node.
            if (node->right == nullptr || node->right == visited_r) {
                answer.push_back(node->val);
                visited_r = node;
                node = nullptr;
                mono_stack.pop();
            } else {
                // goto right, to process its right node
                node = node->right;
            }
        }
        return answer;
    }
};