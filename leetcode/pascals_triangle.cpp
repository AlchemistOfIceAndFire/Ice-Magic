//
// Created by huanyan on 2021/12/23.
//

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer(numRows);
        for (int i = 0; i < numRows; i++) {
            vector<int> path(i + 1);
            path[0] = path[i] = 1;

            for (int j = 1; j < i; j++) {
                path[j] = answer[i - 1][j - 1] + answer[i - 1][j];
            }

            answer[i] = path;
        }
        return answer;
    }
};