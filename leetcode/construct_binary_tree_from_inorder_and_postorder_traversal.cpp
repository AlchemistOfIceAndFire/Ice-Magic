//
// Created by huanyan on 2021/12/15.
//

class Solution {
private:
    map<int, int> index_map;
public:
    TreeNode *build(vector<int> &inorder, int in_l, int in_r, vector<int> &postorder, int post_l, int post_r) {
        if (in_l > in_r || post_l > post_r) {
            return nullptr;
        }

        int in_mid = index_map[postorder[post_r]];
        int left_size = in_mid - in_l;

        TreeNode *node = new TreeNode(postorder[post_r]);
        node->left = build(inorder, in_l, in_mid - 1, postorder, post_l, post_l + left_size - 1);
        node->right = build(inorder, in_mid + 1, in_r, postorder, post_l + left_size, post_r - 1);
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index_map[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};