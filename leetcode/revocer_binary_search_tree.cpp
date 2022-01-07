//
// Created by huanyan on 2021/12/13.
//

void recoverTree(TreeNode *root) {
    stack <pair<TreeNode *, int>> mono_stack;
    mono_stack.push(make_pair(root, 0));

    TreeNode *pre = nullptr, *l = nullptr, *r = nullptr;
    while (!mono_stack.empty()) {
        auto[node, color] = mono_stack.top();
        mono_stack.pop();

        if (node == nullptr) {
            continue;
        }

        if (color == 0) {
            mono_stack.push(make_pair(node->right, 0));
            mono_stack.push(make_pair(node, 1));
            mono_stack.push(make_pair(node->left, 0));
        } else {
            if (pre != nullptr && pre->val > node->val) {
                r = node;
                if (l == nullptr) {
                    l = pre;
                } else {
                    break;
                }
            }
            pre = node;
        }
    }

    int temp = l->val;
    l->val = r->val;
    r->val = temp;
}