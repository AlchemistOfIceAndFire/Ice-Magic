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

void rotate(vector <vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) { return; }
    int nums = matrix.size();
    // represent level
    int times = 0;
    while (times <= (nums >> 1)) {
        int len = nums - (times << 1);
        for (int i = 0; i < len - 1; ++i) {
            int temp = matrix[times][times + i];
            // 每次替换四个数字，分别在四个不同的边上
            // 对于第一个数字A，替换他的数字B，column B = row A, row B = n - i
            matrix[times][times + i] = matrix[times + len - i - 1][times];
            matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
            matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
            matrix[times + i][times + len - 1] = temp;
        }
        ++times;
    }
}

int main() {
    vector<vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16},
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9},
    };
    rotate(matrix);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



