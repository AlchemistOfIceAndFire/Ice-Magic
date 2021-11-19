//
// Created by huanyan on 2021/11/19.
//

class Solution {
public:
    string simplifyPath(string path) {
        vector <string> stack;
        int i = 0, n = path.size();
        while (i < n) {
            if (path[i] == '/') {
                i++;
                continue;
            }

            string s;
            for (; i < n && path[i] != '/'; i++) {
                s += path[i];
            }

            if (s == ".") {
                continue;
            } else if (s == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(s);

            }
        }

        if (stack.empty()) {
            return "/";
        }

        string answer;
        for (int i = 0; i < stack.size(); i++) {
            answer += "/" + stack[i];
        }
        return answer;
    }
};