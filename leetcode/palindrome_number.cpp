//
// Created by huanyan on 2021/8/15.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> nums;
        while (x > 0) {
            int num = x % 10;
            x = x / 10;
            nums.push_back(num);
        }

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] != nums[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0) {
            return false;
        }

        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return x == y || x == y / 10;
    }
};