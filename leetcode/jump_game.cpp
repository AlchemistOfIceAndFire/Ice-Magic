//
// Created by huanyan on 2021/9/9.
//

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int most_right = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > most_right) {
                return false;
            }
            most_right = max(most_right, i + nums[i]);
            if (most_right >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};