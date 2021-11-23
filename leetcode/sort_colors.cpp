//
// Created by huanyan on 2021/11/22.
//

class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int> &nums) {
        int l = 0, r = 1, n = nums.size();
        while (r < n) {
            if (nums[l] > nums[r]) {
                swap(nums, l, r);
            }
            int _l = l;
            while (_l > 0 && nums[_l] < nums[_l - 1]) {
                swap(nums, _l, _l - 1);
                _l--;
            }
            l++;
            r++;
        }
    }

    void sortColors(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, i = 0;
        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums, l++, i++);
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums, i, r--);
            }
        }
    }
};