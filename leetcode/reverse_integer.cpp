//
// Created by huanyan on 2021/8/16.
//

class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        int left = 0x80000000, right = 0x7fffffff;

        while (x != 0) {
            if (answer < left / 10 || (answer == left / 10 && x % 10 < -8)) {
                return 0;
            }
            if (answer > right / 10 || (answer == right / 10 && x % 10 > 7)) {
                return 0;
            }
            answer = answer * 10 + x % 10;
            x = x / 10;
        }

        return answer;
    }
};