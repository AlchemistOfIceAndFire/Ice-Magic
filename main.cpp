//
// Created by huanyan on 2021/8/10.
//

/*
 *
 * if match:
 *    path.push
 *    visited = true
 * else:
 *    return
 *
 */

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

int largestRectangleArea(vector<int> &heights) {
    int answer = 0, n = heights.size();
    stack<int> mono_stack;

    vector<int> _heights = {0};
    _heights.push_back(heights);

    heights.push_back({0});

}

int main() {
//Input:
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    vector<char> path;
    cout << dfs(board, visited, word, path, 0, 0);

// 'ABCCED'
}



