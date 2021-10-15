
//
// Created by huanyan on 2021/10/15.
//

class Solution {
public:
    int trap(vector<int> &height) {
        int answer = 0, left_max = 0, right_max = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] > left_max ? left_max = height[left] : answer += (left_max - height[left]);
                left++;
            } else {
                height[right] > right_max ? right_max = height[right] : answer += (right_max - height[right]);
                right--;
            }
        }
        return answer;
    }
};