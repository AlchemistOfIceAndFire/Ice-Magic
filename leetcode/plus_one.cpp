//
// Created by huanyan on 2021/11/18.
//

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry_bit = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry_bit == 0) {
                break;
            }
            int num = digits[i] + carry_bit;
            carry_bit = num / 10;
            digits[i] = num % 10;
        }

        vector<int> answer(digits.size() + carry_bit);
        if (carry_bit == 1) {
            answer[0] = carry_bit;
        }
        for (int i = 0; i < digits.size(); i++) {
            answer[i + carry_bit] = digits[i];
        }

        return answer;
    }

    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] = ++digits[i] % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }

        digits.resize(digits.size() + 1);
        digits[0] = 1;
        return digits;
    }
};