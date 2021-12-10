//
// Created by huanyan on 2021/12/9.
//

class Solution {
public:
    void dfs(vector <vector<int>> &answer, vector<int> &path, vector<int> &nums, int begin, int end) {
        answer.push_back(path);

        if (begin == end) {
            return;
        }

        for (int i = begin; i < end; i++) {
            path.push_back(nums[i]);
            dfs(answer, path, nums, i + 1, end);
            path.pop_back();

            while (i + 1 < end && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return;
    }

    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        vector <vector<int>> answer;
        vector<int> path;
        sort(nums.begin(), nums.end());

        dfs(answer, path, nums, 0, nums.size());

        return answer;
    }
};