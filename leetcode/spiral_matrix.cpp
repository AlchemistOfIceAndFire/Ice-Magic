//
// Created by huanyan on 2021/11/3.
//

class Solution {
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> answer;

        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                answer.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                answer.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    answer.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    answer.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return answer;
    }
};