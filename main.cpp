//
// Created by huanyan on 2021/8/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <leetcode/model.cpp>
#include <math.h>
#include <stack>
#include <alloca.h>
#include <string.h>
#include <bitset>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
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
            if (stack.size() > 0) {
                stack.pop_back();
            }
        } else {
            stack.push_back(s);

        }
    }

    string answer;
    for (int i = 0; i < stack.size(); i++) {
        answer += "/" + stack[i];
    }
    return answer;
}

int main() {
}



