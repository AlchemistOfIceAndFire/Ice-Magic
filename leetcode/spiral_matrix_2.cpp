//
// Created by huanyan on 2021/11/8.
//

class Solution {
public:
    vector <vector<int>> generateMatrix(int n) {
        vector <vector<int>> answer(n, vector<int>(n, 0));
        int num = 1;

        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right) {
            for (int column = left; column <= right; column++) {
                answer[top][column] = num++;
            }
            for (int row = top + 1; row <= bottom; row++) {
                answer[row][right] = num++;
            }
            if (left < right) {
                for (int column = right - 1; column > left; column--) {
                    answer[bottom][column] = num++;
                }
                for (int row = bottom; row > top; row--) {
                    answer[row][left] = num++;
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