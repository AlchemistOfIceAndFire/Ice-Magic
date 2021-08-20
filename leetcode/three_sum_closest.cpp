//
// Created by huanyan on 2021/8/16.
//

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int answer = nums[0] + nums[1] + nums[2], n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (abs(sum - target) < abs(answer - target)) {
                    answer = sum;
                }
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    return target;
                }
            }
        }
        return answer;
    }
};