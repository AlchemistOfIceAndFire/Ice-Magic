//
// Created by huanyan on 2021/9/6.
//

/*
 * l, r
 * i ~ n, 0 ~ i -1;
 *
 * 二分选择一个位置，必然导致左右两个数组，其中一个是有序的，另一个无序，通过对有序数组进行常规二分，否则则在另一个数组中，来简化各种可能的cases
 *
 * if nums[l~mid] 有序
 *      if target > nums[l] and target < num[mid], target in l ~ mid-1;
 *      else target in mid+1 ~ r;
 *
 * if nums[mid~r] 有序
 *      if target > nums[mid] and target < nums[r], target in mid+1 ~ r;
 *      else target in l ~ mid-1;
 *
 */

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (target == nums[mid]) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
