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


string countAndSay(int n) {
    string answer = "1";
    for (int i = 1; i < n; i++) {
        int counter = 1;
        string temp = "";
        for (int j = 0; j < answer.size(); j++) {
            if (j < answer.size() - 1 && answer[j] == answer[j + 1]) {
                counter++;
                continue;
            }
            temp = temp + to_string(counter) + answer[j];
        }
        answer = temp;
    }
    return answer;
}


int main() {
    cout << countAndSay(4) << endl;
}



