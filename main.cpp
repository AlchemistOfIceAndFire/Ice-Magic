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

using namespace std;


/*
 *
 *  12258
 *  1   2   2   5   8
 *  12  2   5   8
 *  12  25  8
 *  1   22  5
 *
 *  dp[1] = 1; 1
 *  dp[12] = 2; 1 2, 12
 *  dp[122] = 3; 1 2 2, 12 2, 1 22
 *  dp[1225] = 5; 1 2 2 5, 1 22 5, 1 2 25, 12 2 5, 12 25.
 *  dp[12258] = 5; 1 2 2 5 8, 1 22 5 8, 1 2 25 8, 12 2 5 8, 12 25 8.
 *
 *  dp[xxx] = dp[xx] + 1/0
 */


int translateNum(int num) {
    stringstream stream;
    stream << num;
    string str = stream.str();

    int answer = 1;

    for (int i = 1; i < str.size(); i++) {
        int add = str[i] - '0' > 5 ? 0 : 1;
        answer += add;
    }
    return answer;
}

int nthUglyNumber(int n) {
    vector<int> factors = {2, 3, 5};
    unordered_set<long> visited;
    priority_queue<long, vector<long>, greater<long>> q;
    q.push(1);

    for (int i = 1; i < n; i++) {
        int heap = q.top();
        q.pop();

        for (int j = 0; j < factors.size(); j++) {
            long num = heap * factors[j];
            if (visited.count(num) > 0) {
                continue;
            }
            visited.insert(num);
            q.push(num);
        }
    }
    return (int)q.top();
}

int main() {
    int result = nthUglyNumber(2);
    cout << result;
}



