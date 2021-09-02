//
// Created by huanyan on 2021/8/24.
//

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2 || s.size() % 2 == 1) {
            return false;
        }

        stack<char> stack;
        map<char, char> pairs = {
                {'}', '{'},
                {']', '['},
                {')', '('},
        };

        for (int i = 0; i < s.size(); i++) {
            if (pairs.count(s[i]) > 0 && (stack.size() == 0 || stack.top() != pairs[s[i]])) {
                return false;
            } else if (pairs.count(s[i]) > 0 && stack.top() == pairs[s[i]]) {
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};