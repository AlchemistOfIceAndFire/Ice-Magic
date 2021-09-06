//
// Created by huanyan on 2021/8/23.
//

class Solution {
public:
    void dfs(int begin, int end, int num, vector<vector<int>> &answer, vector<int> &path) {
        if (path.size() == end) {
            answer.push_back(path);
            return;
        }

        // each number just can be used once in each answer, so each recursion begin at i+1, jump to current number, and the preve number should be ignored by other recursion
        for (int i = begin; i < num; i++) {
            path.push_back(i + 1);
            dfs(i + 1, end, num, answer, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> path;
        dfs(0, k, n, answer, path);
        return answer;
    }
};
