//
// Created by huanyan on 2021/8/18.
//

class Solution {
public:
    int maxArea(vector<int> &height) {
        int answer = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int capacity = (r - l) * min(height[l], height[r]);
            answer = max(answer, capacity);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return answer;
    }
};