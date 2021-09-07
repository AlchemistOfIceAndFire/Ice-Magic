//
// Created by huanyan on 2021/8/24.
//

class Solution {
public:
    vector <vector<int>> fourSum(vector<int> &nums, int target) {
        vector <vector<int>> answer;
        sort(nums.begin(), nums.end());

        // if nums's length < 4, return directly
        if (nums.size() < 4) {
            return answer;
        }

        // i represent the first number, so the left three numbers didn't need to iterate.
        for (int i = 0; i < nums.size() - 3; i++) {
            // avoid duplication
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; j++) {
                // avoid duplication
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                // two ptr iterate nums to avoid twice iteration
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long sum = long(nums[i]) + long(nums[j]) + long(nums[l]) + long(nums[r]);
                    if (sum == target) {
                        answer.push_back({nums[i], nums[j], nums[l], nums[r]});
                        // avoid duplication
                        while (l < r && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        // avoid duplication
                        while (l < r && nums[r] == nums[r - 1]) {
                            r--;
                        }
                        l++;
                        r--;
                    } else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return answer;
    }
};