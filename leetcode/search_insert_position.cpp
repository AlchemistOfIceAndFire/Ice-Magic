//
// Created by huanyan on 2021/9/7.
//

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                // if target in the mid's left, if mid-1 > target, the mid's position is the answer
                if (mid - 1 < 0 || nums[mid - 1] < target) {
                    return mid;
                }
                // else continually search
                r = mid - 1;
            } else {
                // if target in the mid's right, continually search, just move to the most right, return mid +1, because target is the largest number
                if (mid == n - 1) {
                    return mid + 1;
                }
                l = mid + 1;
            }
        }
        return -1;
    }
};