//
// Created by huanyan on 2021/12/1.
//

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), answer = 0;
        vector <vector<int>> lefts(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                lefts[i][j] = (j == 0 ? 0 : lefts[i][j - 1]) + 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }

                int width = lefts[i][j];
                answer = max(answer, width);
                for (int k = i - 1; k >= 0; k--) {
                    width = min(width, lefts[k][j]);
                    answer = max(answer, (i - k + 1) * width);
                }
            }
        }

        return answer;
    }
};