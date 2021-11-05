//
// Created by huanyan on 2021/9/9.
//

class Solution {
public:
    bool canJump(vector<int> &nums) {
        // most_right mark the farthest reachable distance
        int most_right = 0;
        // iterate each index to calculate the max distance from this position
        for (int i = 0; i < nums.size(); i++) {
            // this case means we cannot reach position i, return false
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