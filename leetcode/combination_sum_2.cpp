//
// Created by huanyan on 2021/8/23.
//

/*
 * [2,5,2,1,2], target = 5
 * sorted:
 *
 * [1, 2, 2, 2, 5], target = 5
 *
 */

class Solution {
public:
    void dfs(vector<vector<int>> &answer, vector<int> &path, vector<int> &candidates, int target, int begin, int n) {
        if (target == 0) {
            answer.push_back(path);
        }

        for (int i = begin; i < n; i++) {
            if (target < candidates[i]) {
                return;
            }

            path.push_back(candidates[i]);
            dfs(answer, path, candidates, target - candidates[i], i + 1, n);
            path.pop_back();
            // each number just can use once in each answer, so if the next number equals prev number, the next number can be used in next recursion,
            // so to avoid the repeated answer, current recursion iteration jump the same number, just use once, and the other same numbers are used for following recursion
            while (i + 1 < n && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> answer;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(answer, path, candidates, target, 0, candidates.size());
        return answer;
    }
};