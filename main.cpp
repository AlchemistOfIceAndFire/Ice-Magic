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

using namespace std;

/*
 *  map<vector<int>> 标记每行的数字
 *  map<vector<int>> 标记每列的数字
 *  map<vector<int>> 标记每个3*3是否出现重复数字
 *  vector<int> [-1, 1, 0, 0] vector<int> [0, 0, -1, 1] 用来执行当前单元格的上下左右查找
 *  counter 计数当前所处3*3
 *
 *
 */

int longestValidParentheses(string s) {
    int answer = 0, counter = 0;
    vector<char> stack;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (!stack.empty()) {
                counter++;
                stack.pop_back();
            } else {
                stack.clear();
            }
            continue;
        }
        stack.push_back(s[i]);
    }
    return answer;
}

int main() {

}



