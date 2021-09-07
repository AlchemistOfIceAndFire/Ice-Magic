//
// Created by huanyan on 2021/9/7.
//

class Solution {
public:
    bool isValidSudoku(vector <vector<char>> &board) {
        vector <vector<int>> row_checker(9, vector<int>(9));
        vector <vector<int>> column_checker(9, vector<int>(9));
        vector <vector<int>> sub_board_checker(9, vector<int>(9));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // if . continue
                if (board[i][j] == '.') {
                    continue;
                }
                // if current number exist in three maps return false
                int counter = (j / 3) * 3 + (i / 3), num = board[i][j] - '0' - 1;

                if (row_checker[i][num] != 0) {
                    return false;
                }
                if (column_checker[j][num] != 0) {
                    return false;
                }
                if (sub_board_checker[counter][num] != 0) {
                    return false;
                }

                row_checker[i][num] = 1;
                column_checker[j][num] = 1;
                sub_board_checker[counter][num] = 1;
            }
        }
        return true;
    }
};