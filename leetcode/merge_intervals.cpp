//
// Created by huanyan on 2021/11/4.
//

class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> answer;

        for (int i = 0; i < intervals.size(); i++) {
            // if i = 0, it will add to answer directly, and in the iteration process, we need to modify old item or add new item.
            int l = intervals[i][0], r = intervals[i][1];
            if (answer.size() == 0 || answer.back()[1] < l) {
                answer.push_back({l, r});
            } else {
                answer.back()[1] = max(answer.back()[1], r);
            }
        }
        return answer;
    }
};