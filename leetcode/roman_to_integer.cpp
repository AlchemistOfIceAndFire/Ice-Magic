//
// Created by huanyan on 2021/8/16.
//

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> symbols = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
                };

        int answer = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && symbols[s[i]] < symbols[s[i + 1]]) {
                answer -= symbols[s[i]];
            } else {
                answer += symbols[s[i]];
            }
        }
        return answer;
    }
};
