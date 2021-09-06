//
// Created by huanyan on 2021/9/6.
//

/*
 * 6 3 4 2
 *
 * 6 4 3 2
 *
 * 6 4 2 3
 *
 * from the tail to front, find the first number nums[i] satisfy to nums[i] < nums[j]. following the i. from i+1 ~ n is desc order
 *
 * from tail to i+1, find the first number nums[j] satisfy to nums[i] < nums[j].
 *
 * because from i+1 to n is desc order, so swap the nums[i] and nums[j], from i+1 to n always is desc order.
 * so order the from i+1 to n, change it to asc order, this is the next number as answer.
 *
 * 比如千位进一后，后面的数从小到大排列才是进位后最小的数字
 *
 */

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while (i > -1 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i > -1) {
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};