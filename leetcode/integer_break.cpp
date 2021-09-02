
//
// Created by huanyan on 2021/8/24.
//

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }

        int three_count = n / 3;
        int left = n % 3;

        int answer = pow(3, three_count - 1);

        if (left == 0) {
            answer = answer * 3;
        }
        if (left == 1) {
            answer = answer * pow(left + 1, 2);
        }
        if (left == 2) {
            answer = answer * left * 3;
        }
        return answer;
    }
};