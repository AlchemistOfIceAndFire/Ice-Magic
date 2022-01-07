//
// Created by huanyan on 2022/1/4.
//

class Solution {
private:
    int id = -1;
    map<string, int> ids;
    map<int, vector<int>> dict;
public:
    int generateId(string &word) {
        if (ids.count(word)) {
            return ids[word];
        }
        ids[word] = ++id;
        return id;
    }

    void generateDict(string &word) {
        int org_id = generateId(word);
        for (char &it: word) {
            char tmp = it;
            it = '*';
            int sub_id = generateId(word);
            dict[org_id].push_back(sub_id);
            dict[sub_id].push_back(org_id);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
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

        if (!ids.count(endWord)) {
            return 0;
        }

        while (!q_id.empty()) {
            int cur_id = q_id.front();
            q_id.pop();

            if (cur_id == generateId(endWord)) {
                return dp[cur_id] / 2 + 1;
            }

            vector<int> nexts = dict[cur_id];
            for (int i = 0; i < nexts.size(); i++) {
                if (dp[nexts[i]] != -1) {
                    continue;
                }
                dp[nexts[i]] = dp[cur_id] + 1;
                q_id.push(nexts[i]);
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
        generateDict(beginWord);
        for (string &word: wordList) {
            generateDict(word);
        }

        if (!ids.count(endWord)) {
            return 0;
        }

        vector<int> dp_begin(id + 1, -1);
        dp_begin[generateId(beginWord)] = 0;
        queue<int> q_begin;
        q_begin.push(generateId(beginWord));

        vector<int> dp_end(id + 1, -1);
        dp_end[generateId(endWord)] = 0;
        queue<int> q_end;
        q_end.push(generateId(endWord));

        while (!q_begin.empty() && !q_end.empty()) {
            int q_begin_size = q_begin.size();
            for (int i = 0; i < q_begin_size; i++) {
                int cur_id = q_begin.front();
                q_begin.pop();

                if (dp_end[cur_id] != -1) {
                    return (dp_begin[cur_id] + dp_end[cur_id]) / 2 + 1;
                }

                for (int &next_id: dict[cur_id]) {
                    if (dp_begin[next_id] == -1) {
                        dp_begin[next_id] = dp_begin[cur_id] + 1;
                        q_begin.push(next_id);
                    }
                }
            }

            int q_end_size = q_end.size();
            for (int i = 0; i < q_end_size; i++) {
                int cur_id = q_end.front();
                q_end.pop();

                if (dp_begin[cur_id] != -1) {
                    return (dp_begin[cur_id] + dp_end[cur_id]) / 2 + 1;
                }

                for (int &next_id: dict[cur_id]) {
                    if (dp_end[next_id] == -1) {
                        dp_end[next_id] = dp_end[cur_id] + 1;
                        q_end.push(next_id);
                    }
                }
            }
        }
        return 0;
    }
};