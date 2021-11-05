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

vector<int> selectNext(int i, int j, int n) {
    return {j, n - 1 - i};
}

/*
 * t_row = n-1-row;
 * t_column =
 *
 */
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    if (intervals.size() == 0) {
        return {newInterval};
    }
    if (newInterval.size() == 0) {
        return intervals;
    }

    vector<vector<int>> answer;
    bool flag = false;
    int nl = newInterval[0], nr = newInterval[1];
    for (int i = 0; i < intervals.size(); i++) {
        int l = intervals[i][0], r = intervals[i][1];
        if (l > nr && i == 0) {
            answer.push_back({nl, nr});
        } else if (r < nl && i == intervals.size() - 1) {
            answer.push_back({nl, nr});
        } else if (r < nl || l > nr) {
            answer.push_back({l, r});
        } else {
            if (!flag) {
                answer.push_back({nl, nr});
                flag = true;
            }
            answer.back()[0] = min(answer.back()[0], l);
            answer.back()[1] = max(answer.back()[1], r);
        }
    }
    return answer;
}

int main() {

}



