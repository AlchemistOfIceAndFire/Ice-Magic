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

ListNode *partition(ListNode *head, int x) {
    ListNode *left = new ListNode(), *left_head = left, *right = new ListNode(), *right_head = right;

    while (head != nullptr) {
        if (head->val < x) {
            left->next = head;
            left = left->next;
        } else {
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }

    right->next = nullptr;
    left->next = right_head->next;
    return left_head->next;
}


int main() {
//Input:
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    vector<char> path;

// 'ABCCED'
}



