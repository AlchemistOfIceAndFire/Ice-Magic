//
// Created by huanyan on 2021/8/10.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSumIteration(vector<int> &nums, int target) {
        vector<int> result;
        int i, j;
        for (i = 0; i < nums.size() - 1; i++) {
            int left = target - nums[i];
            for (j = i + 1; j < nums.size(); j++) {
                if (left == nums[j]) {
                    cout << i << " " << j << endl;
                    return {i, j};
                }
            }
        }
        return {i, j};
    }

    vector<int> twoSumMap(vector<int> &nums, int target) {
        map<int, int> dict;
        vector<int> result(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            if (dict.count(target - nums[i]) > 0) {
                result = {nums[target - nums[i]], i};
            }
            dict[nums[i]] = i;
        }
        return result;
    }
};
