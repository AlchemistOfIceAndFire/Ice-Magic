//
// Created by huanyan on 2021/9/26.
//

class Solution {
public:
    bool isValid(vector <string> &path, int row, int column, int n) {
        // judge column
        for (int i = 0; i < row; i++) {
            if (path[i][column] == 'Q') {
                return false;
            }
        }
        // judge above left diagonal
        int i = row - 1, j = column - 1;
        while (i > -1 && j > -1) {
            if (path[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        // judge above right diagonal
        i = row - 1, j = column + 1;
        while (i > -1 && column < n) {
            if (path[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    void queen(vector <vector<string>> &answer, vector <string> &path, int n, int row) {
        if (row == n) {
            answer.push_back(path);
            return;
        }
        for (int column = 0; column < n; column++) {
            if (!isValid(path, row, column, n)) {
                continue;
            }
            path[row][column] = 'Q';
            queen(answer, path, n, row + 1);
            path[row][column] = '.';
        }
    }

    vector <vector<string>> solveNQueens(int n) {
        vector <vector<string>> answer;
        vector <string> path(n, string(n, '.'));
        queen(answer, path, n, 0);
        return answer;
    }
};