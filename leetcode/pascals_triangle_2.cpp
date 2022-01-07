//
// Created by huanyan on 2021/12/23.
//

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer, up_level;
        for (int i = 0; i <= rowIndex; i++) {
            answer.resize(i + 1);
            answer[0] = answer[i] = 1;

            for (int j = 1; j < i; j++) {
                answer[j] = up_level[j - 1] + up_level[j];
            }

            up_level = answer;
        }
        return answer;
    }

    /*
     *                1 . . . . .
     *              1  1 . . . .
     *            1  2  1 . . .
     *          1  3  3  1 . .
     *        1  4  6  4  1 .
     *      1  5  10  10 5  1
     *
     */
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1);
        answer[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                answer[j] = answer[j - 1] + answer[j];
            }
        }
        return answer;
    }
};