//
// Created by huanyan on 2021/8/20.
//

class Solution {
public:
    void
    dfs(vector<int> &nums, vector <vector<int>> &answer, vector<int> &path, vector<bool> &visited, int begin, int n) {
        if (n == begin) {
            answer.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, answer, path, visited, begin + 1, n);
            path.pop_back();
            visited[i] = false;
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }

//    void dfs(vector<int> &nums, vector <vector<int>> answer, int begin, int n) {
//        if (n == begin) {
//            answer.push_back(nums);
//            return;
//        }
//
//        for (int i = begin; i < n; i++) {
//            swap(nums[i], nums[begin]);
//            dfs(nums, answer, begin + 1, n);
//            swap(nums[i], nums[begin]);
//            while (i + 1 < n && nums[i] == nums[i + 1]) {
//                i++;
//            }
//        }
//    }

    vector <vector<int>> permuteUnique(vector<int> &nums) {
        vector <vector<int>> answer;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, answer, path, visited, 0, nums.size());
        return answer;
    }
};