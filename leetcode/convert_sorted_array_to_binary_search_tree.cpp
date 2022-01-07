//
// Created by huanyan on 2021/12/15.
//

class Solution {
public:
    TreeNode *build(vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = build(nums, l, mid - 1);
        node->right = build(nums, mid + 1, r);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }
};