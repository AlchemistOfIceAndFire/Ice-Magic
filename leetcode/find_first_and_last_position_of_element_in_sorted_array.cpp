//
// Created by huanyan on 2021/9/7.
//

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // binary search, avoid compute length of nums multiply
        int n = nums.size(), l = 0, r = n - 1;

        // store the answer, default values are -1 means cannot find the target in nums
        int left = -1, right = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            // if nums[mid] == target and (it is the most left value in nums or its left value unequals target means this position is the most left target)
            if (nums[mid] == target && (mid == 0 || nums[mid] != nums[mid - 1])) {
                left = mid;
                break;
            }
            // if nums[mid] = target means this position is not the most left value with target, need to search continually from l to mid-1.
            // if nums[mid] > target means normal binary search
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // If the target is not found, it means that it did not return directly in advance
        if (left == -1) {
            return {-1, -1};
        }

        // minimize search path
        l = left, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            // if nums[mid] == target and (it is the most right value in nums or its right value unequals target means this position is the most right target)
            if (nums[mid] == target && (mid == n - 1 || nums[mid] != nums[mid + 1])) {
                right = mid;
                break;
            }
            // if nums[mid] = target means this position is not the most right value with target, need to search continually from mid+1 to r.
            // if nums[mid] < target means normal binary search
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {left, right};
    }
};