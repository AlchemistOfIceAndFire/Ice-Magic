//
// Created by huanyan on 2021/8/10.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer(0, vector<int>(3));
        if (nums.empty() || nums.size() < 3) {
            return answer;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                } else if (nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return answer;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer(0, vector<int>(3));
        if (nums.empty() || nums.size() < 3) {
            return answer;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int r = nums.size() - 1;
            for (int l = i + 1; l < nums.size(); l++) {
                if (l > i + 1 && nums[l] == num[l - 1]) {
                    l++;
                }
                while (r > l && num[i] + num[l] + nums[l] > 0) {
                    r--;
                }
                if (l == r) {
                    break;
                }
                if (nums[i] + nums[l] + nums[j] == 0) {
                    answer.push_back({nums[i], nums[l], nums[j]});
                }
            }
        }
        return answer;
    };
