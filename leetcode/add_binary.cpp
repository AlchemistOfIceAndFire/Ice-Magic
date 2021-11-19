//
// Created by huanyan on 2021/11/18.
//

class Solution {
public:
    string addBinary(string a, string b) {

        string answer;
        int carry_bit = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            carry_bit += i >= 0 ? a[i] == '1' : 0;
            carry_bit += j >= 0 ? b[j] == '1' : 0;
            answer.push_back((carry_bit % 2) + '0');
            carry_bit = carry_bit / 2;
        }

        if (carry_bit == 1) {
            answer.push_back('1');
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};