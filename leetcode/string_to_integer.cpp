//
// Created by huanyan on 2021/8/17.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, answer = 0, i;

        for (i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '-' || s[i] == '+') {
                sign = s[i] == '-' ? -1 : 1;
                i++;
                break;
            } else {
                break;
            }
        }

        for (; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                break;
            }
            if (answer < INT32_MIN / 10 || (answer == INT32_MIN / 10 && sign * (s[i] - '0') % 10 < -8)) {
                return INT32_MIN;
            }
            if (answer > INT32_MAX / 10 || (answer == INT32_MAX / 10 && (s[i] - '0') % 10 > 7)) {
                return INT32_MAX;
            }
            answer = answer * 10 + (s[i] - '0') * sign;

        }
        return answer;
    }

    int myAtoi(string s) {
        enum state_machine {
            START, SIGNED, INNUMBER, END
        } STATE;

        map <state_machine, vector<state_machine>> states = {
                {START,    {START, SIGNED, INNUMBER, END}},
                {SIGNED,   {END,   END,    INNUMBER, END}},
                {INNUMBER, {END,   END,    INNUMBER, END}},
                {END,      {END,   END,    END,      END}},
        };

        auto translate_state = [](char c) -> int {
            if (c == ' ') {
                return 0;
            }
            if (c == '+' || c == '-') {
                return 1;
            }
            if (c >= '0' && c <= '9') {
                return 2;
            }
            return 3;
        };

        int answer = 0, sign = 1;
        STATE = START;

        for (int i = 0; i < s.size(); i++) {
            STATE = states[STATE][(s[i])];
            switch (STATE) {
                case START:
                    break;
                case SIGNED:
                    sign = s[i] == '-' ? -1 : 1;
                    break;
                case INNUMBER:
                    if (answer < INT32_MIN / 10 || (answer == INT32_MIN / 10 && sign * (s[i] - '0') < -8)) {
                        return INT32_MIN;
                    }
                    if (answer > INT32_MAX / 10 || (answer == INT32_MAX / 10 && (s[i] - '0') > 7)) {
                        return INT32_MAX;
                    }
                    answer = answer * 10 + sign * (s[i] - '0');
                    break;
                case END:
                    return answer;
            };
        }
        return answer;
    }
};