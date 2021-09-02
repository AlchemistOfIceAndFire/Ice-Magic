//
// Created by huanyan on 2021/8/31.
//

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0, fast = 0, n = nums.size();
        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};