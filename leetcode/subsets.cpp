//
// Created by huanyan on 2021/11/23.
//

class Solution {
public:
    void dfs(vector <vector<int>> &answer, vector<int> &nums, vector<int> &path, int begin, int end) {
        answer.push_back(path);

        if (begin == end) {
            return;
        }

        for (int i = begin; i < end; i++) {
            path.push_back(nums[i]);
            dfs(answer, nums, path, i + 1, end);
            path.pop_back();
        }
    }

    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> answer;
        vector<int> path;

        dfs(answer, nums, path, 0, nums.size());

        return answer;
    }
};