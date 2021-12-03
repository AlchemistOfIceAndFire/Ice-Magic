//
// Created by huanyan on 2021/12/1.
//

/*
 * this question is absolutely same to largest_rectangle_in_histogram
 *
 * juse have the additional step, you need to calculate the height for matrix, you can iterate it levelly
 *
 */

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

    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int answer = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 1, 0);

        for (int i = 0; i < m; i++) {
            stack<int> mono_stack;
            mono_stack.push(0);

            for (int j = 0; j < n + 1; j++) {
                if (j < n) {
                    if (matrix[i][j] == '0') {
                        heights[j] = 0;
                    } else {
                        heights[j] += 1;
                    }
                }

                while (!mono_stack.empty() && heights[j] < heights[mono_stack.top()]) {
                    int height = heights[mono_stack.top()];
                    mono_stack.pop();

                    int width = j;
                    if (!mono_stack.empty()) {
                        width = width - mono_stack.top() - 1;
                    }
                    answer = max(answer, height * width);
                }
                mono_stack.push(j);
            }
        }
        return answer;
    }

    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int answer = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 2, 0);

        for (int i = 0; i < m; i++) {
            stack<int> mono_stack;
            mono_stack.push(0);

            for (int j = 1; j < n + 2; j++) {
                if (j < n + 1) {
                    if (matrix[i][j - 1] == '0') {
                        heights[j] = 0;
                    } else {
                        heights[j] += 1;
                    }
                }

                while (heights[j] < heights[mono_stack.top()]) {
                    int height = heights[mono_stack.top()];
                    mono_stack.pop();
                    int width = j - mono_stack.top() - 1;
                    answer = max(answer, height * width);
                }
                mono_stack.push(j);
            }
        }
        return answer;
    }

    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int answer = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> lefts(n, -1), rights(n, n), heights(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            int l_boundary = -1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    lefts[j] = max(lefts[j], l_boundary);
                } else {
                    lefts[j] = -1;
                    l_boundary = j;
                }
            }

            int r_boundary = n;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    rights[j] = min(rights[j], r_boundary);
                } else {
                    rights[j] = n;
                    r_boundary = j;
                }
            }

            for (int j = 0; j < n; j++) {
                answer = max(answer, heights[j] * (rights[j] - lefts[j] - 1));
            }
        }

        return answer;
    }
};