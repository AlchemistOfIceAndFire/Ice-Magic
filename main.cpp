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

/*
 *  map<vector<int>> 标记每行的数字
 *  map<vector<int>> 标记每列的数字
 *  map<vector<int>> 标记每个3*3是否出现重复数字
 *  vector<int> [-1, 1, 0, 0] vector<int> [0, 0, -1, 1] 用来执行当前单元格的上下左右查找
 *  counter 计数当前所处3*3
 *
 *
 */
vector<bitset<9>> rows;
vector<bitset<9>> columns;
vector<vector<bitset<9>>> cells;

bitset<9> getAvailableNum(int i, int j) {
    return ~(rows[i] | columns[j] | cells[i / 3][j / 3]);
}

void fillStatus(int i, int j, int num, bool flag) {
    rows[i][num] = flag ? 1 : 0;
    columns[j][num] = flag ? 1 : 0;
    cells[i / 3][j / 3][num] = flag ? 1 : 0;
}

vector<int> selectNext(vector<vector<char>> &board) {
    vector<int> next;
    int minAvailableNumCount = 10;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            bitset<9> bits = getAvailableNum(i, j);
            if (bits.count() > minAvailableNumCount) {
                continue;
            }
            next = {i, j};
            minAvailableNumCount = bits.count();
        }
    }
    return next;
}

bool dfs(vector<vector<char>> &board, int count) {
    if (count == 0) {
        return true;
    }

    for (int num = 0; num < 9; num++) {
        vector<int> next = selectNext(board);
        bitset<9> bits = getAvailableNum(next[0], next[1]);
        if (bits.test(num)) {
            continue;
        }
        fillStatus(next[0], next[1], num, true);
        board[next[0]][next[1]] = num + '0' + 1;
        if (dfs(board, count - 1)) {
            return true;
        }
        fillStatus(next[0], next[1], num, false);
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    rows = vector<bitset<9>>(9, bitset<9>(0));
    columns = vector<bitset<9>>(9, bitset<9>(0));
    cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>(0)));
    int count = 0;
    // init the rows, columns and cells, and accumulate how many blank need to fill number
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                count++;
            } else {
                int num = board[i][j] - '0' - 1;
                fillStatus(i, j, num, true);
            }
        }
    }
}

int main() {
}



