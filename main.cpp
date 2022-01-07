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

/*
 *  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *  Output: [3,9,20,null,null,15,7]
 *
 *  root = 3
 *  left = [9]
 *  right = [15 20 7]
 *
 *
 *
 */


using namespace std;

class Solution {
private:
    int id = -1;
    map<string, int> ids;
    map<int, vector<int>> &dict;
public:
    int generateId(string &word) {
        if (ids.count(word)) {
            return ids[word];
        }
        ids[word] = ++id;
        return id;
    }

    void generateDict(string &word) {
        generateId(word);
        int org_id = ids[word];
        for (char &it: word) {
            char tmp = it;
            it = '*';
            int sub_id = generateId(word);
            dict[org_id].push_back(sub_id);
            dict[sub_id].push_back(org_id);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        generateDict(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            generateDict(wordList[i]);
        }

        // this dp vector means transfer beginWord to array id need how many steps
        vector<int> dp(id + 1, -1);
        dp[generateId(beginWord)] = 0;

        // this queue means current we can transfered words
        queue<int> q_id;
        q_id.push(generateId(beginWord));

        while (!q_id.empty()) {
            int cur_id = q_id.front();
            q_id.pop();

            if (cur_id == generateId(endWord)) {
                return dp[cur_id] / 2 + 1;
            }

            vector<int> nexts = dict[cur_id];
            for (int i = 0; i < nexts.size(); i++) {
                if (dp[nexts[i] == -1]) {
                    continue;
                }
                dp[nexts[i]] = dp[cur_id] + 1;
                q_id.push(nexts[i]);
            }
        }
        return 0;
    }
};

int main() {

}



