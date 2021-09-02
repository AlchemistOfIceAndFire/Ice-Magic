//
// Created by huanyan on 2021/8/23.
//

class Solution {
public:
    void dfs(vector<int> &candidates, vector <vector<int>> &answer, vector<int> &path, int target, int begin, int n) {
        if (target == 0) {
            answer.push_back(path);
            return;
        }

        for (int i = begin; i < n; i++) {
            if (target < candidates[i]) {
                return;
            }
            path.push_back(candidates[i]);
            dfs(candidates, answer, path, target - candidates[i], i, n);
            path.pop_back();
        }
    }

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector <vector<int>> answer;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, answer, path, target, 0, candidates.size());
        return answer;
    }
};
