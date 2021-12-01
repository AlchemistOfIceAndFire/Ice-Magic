//
// Created by iedwa on 2021/9/13.
//

class Solution {
public:
    int jump(vector<int> &nums) {
        int answer = 0, right = 0, max_right = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            max_right = max(max_right, i + nums[i]);
            if (max_right >= n - 1) {
                answer++;
                break;
            }
            if (i == right) {
                right = max_right;
                answer++;
            }
        }
        return answer;
    }

    int jump(vector<int> &nums) {
        int pos = nums.size() - 1, answer = 0;
        while (pos > 0) {
            for (int i = 0; i < pos; i++) {
                if (i + nums[i] >= pos){
                    pos = i;
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};