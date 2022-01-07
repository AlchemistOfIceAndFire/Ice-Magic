//
// Created by huanyan on 2021/12/14.
//

class Solution {
private:
    map<int, int> index_map;
public:
    TreeNode *build(vector<int> &preorder, int pre_l, int pre_r, vector<int> &inorder, int in_l, int in_r) {
        if (pre_l > pre_r || in_l > in_r) {
            return nullptr;
        }

        int in_mid = index_map[preorder[pre_l]];
        int left_size = in_mid - in_l;

        TreeNode *node = new TreeNode(preorder[pre_l]);
        node->left = build(preorder, pre_l + 1, pre_l + left_size, inorder, in_l, in_mid - 1);
        node->right = build(preorder, pre_l + left_size + 1, pre_r, inorder, in_mid + 1, in_r);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index_map[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int pre_l, int pre_r, vector<int> &inorder, int in_l, int in_r) {
        if (pre_l > pre_r || in_l > in_r) {
            return nullptr;
        }


        int in_mid = 0;
        for (int i = in_l; i <= in_r; i++) {
            if (preorder[pre_l] == inorder[i]) {
                in_mid = i;
                break;
            }
        }

        TreeNode *node = new TreeNode(preorder[pre_l]);
        node->left = build(preorder, pre_l + 1, pre_l + in_mid - in_l, inorder, in_l, in_mid - 1);
        node->right = build(preorder, pre_l + in_mid - in_l + 1, pre_r, inorder, in_mid + 1, in_r);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};