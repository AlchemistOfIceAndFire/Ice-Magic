//
// Created by huanyan on 2021/8/20.
//

class Solution {
public:
    void
    dfs(vector<int> &nums, vector <vector<int>> &answer, vector<int> &path, vector<bool> visited, int begin, int n) {
        if (begin == nums.size()) {
            answer.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, answer, path, visited, begin + 1, n);
            path.pop_back();
            visited[i] = false;
        }
    }

    void dfs(vector<int> &nums, vector <vector<int>> &answer, int begin, int n) {
        if (begin == n) {
            answer.push_back(nums);
            return;
        }

        for (int i = begin; i < n; i++) {
            swap(nums[i], nums[begin]);
            dfs1(nums, answer, begin + 1, n);
            swap(nums[i], nums[begin]);
        }
    }

    vector <vector<int>> permute(vector<int> &nums) {
        vector <vector<int>> answer;
        vector<int> path;
        vector<bool> visited(nums.size(), false);

        dfs(nums, answer, path, visited, 0, nums.size());
        return answer;
    }
};