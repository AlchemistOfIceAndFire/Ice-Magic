//
// Created by huanyan on 2021/8/13.
//

class Solution {
public:
    string intToRoman(int num) {
        vector<int> ints = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector <string> romans = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string answer = "";
        for (int i = 12; i > -1; i--) {
            while (num >= ints[i]) {
                answer += romans[i];
                num -= ints[i];
            }
        }
        return answer;
    }
};