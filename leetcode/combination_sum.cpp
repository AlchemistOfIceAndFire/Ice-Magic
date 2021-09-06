//
// Created by huanyan on 2021/8/23.
//

class Solution {
public:
    void dfs(vector<int> &candidates, vector <vector<int>> &answer, vector<int> &path, int target, int begin, int n) {
        // if target = 0 means the sum of numbs in path equals target
        if (target == 0) {
            answer.push_back(path);
            return;
        }

        // Numbers can be reused, but the result set cannot be repeated, so the next recursion start at current i index.
        for (int i = begin; i < n; i++) {
            // if current candidate > target means the following number all > target, directly return
            if (target < candidates[i]) {
                return;
            }
            path.push_back(candidates[i]);
            dfs(candidates, answer, path, target - candidates[i], i, n);
            path.pop_back();
        }
    }

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        // used to store returned answer
        vector <vector<int>> answer;
        // used to store evey answer
        vector<int> path;
        // sort candidates
        sort(candidates.begin(), candidates.end());
        dfs(candidates, answer, path, target, 0, candidates.size());
        return answer;
    }
};
