//
// Created by huanyan on 2021/11/19.
//

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, answer = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((long long) mid * mid <= x) {
                answer = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return answer;
    }
};