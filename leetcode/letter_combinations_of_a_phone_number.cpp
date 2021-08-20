//
// Created by huanyan on 2021/8/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map <string, string> dict = {
                {"2", "abc"},
                {"3", "def"},
                {"4", "ghi"},
                {"5", "jkl"},
                {"6", "mno"},
                {"7", "pqrs"},
                {"8", "tuv"},
                {"9", "wxyz"},
        };

        vector<string> answer(0);
        vector<string> char_array(digtis.size());
        for (int i = 0; i < digits.size(); i++) {
            char_array.push_back(dict[digits[i]]);
        }

        for (int i = 0; i < char_array[0].size()) {
            for (j = 0; j < 4; j++) {
                temp = char_array[0][i];
                for (int k = 1; k < char_array.size(); k++) {
                    if (char_array[k].size() < 4) {
                        continue;
                    }
                    temp = temp + char_array[k][i]
                }
                answer.push_back(temp);
            }
        }
        return answer;
    }
};
