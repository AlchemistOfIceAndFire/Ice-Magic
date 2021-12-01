//
// Created by huanyan on 2021/11/25.
//

/*
 * l = 0, r = 0
 * the first element have two at most, so when i >= 2, start to use the l and r ptr.
 *
 * l means which index need to be replaced
 * r means replaced num
 * this code check each item representatively, and have ineffectively replacing -> swap(i,i)
 * r always point to which replace num
 *
 * l represents this idx is more than 2, and r represents next num and no equal nums[l]
 *
 */

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (l < 2 || nums[l - 2] != nums[r]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};