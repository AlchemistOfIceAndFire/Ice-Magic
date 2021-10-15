//
// Created by huanyan on 2021/10/14.
//

class Solution {
public:
    vector <bitset<9>> row_checker;
    vector <bitset<9>> column_checker;
    vector <bitset<9>> sub_board_checker;

    vector<int> gotoNext(int row, int column) {
        if (row == 8 && column == 8) {
            return {-1, -1};
        }
        if (column < 8) {
            return {row, column + 1};
        } else {
            return {row + 1, 0};
        }
    }

    void setChecker(int row, int column, int num) {
        int sub_board_pos = (row / 3) * 3 + (column / 3);
        row_checker[row][num] = row_checker[row][num] ? 0:1;
        column_checker[column][num] = column_checker[column][num] ? 0:1;
        sub_board_checker[sub_board_pos][num] = sub_board_checker[sub_board_pos][num] ? 0:1;
    }

    bitset<9> judgeChecker(int row, int column, int num) {
        int sub_board_pos = (row / 3) * 3 + (column / 3);

        return ~(row_checker[row] | column_checker[column] | sub_board_checker[sub_board_pos]);
    }

    bool conquer(vector <vector<char>> &board, int row, int column) {
        if (row == -1 && column == -1) {
            return true;
        }

        bool isValid = false;
        vector<int> nextPos = gotoNext(row, column);

        if (board[row][column] != '.') {
            isValid = conquer(board, nextPos[0], nextPos[1]);
        } else {
            for (int num = 0; num < 9; num++) {
                if (!judgeChecker(row, column, num).test(num)) {
                    continue;
                }
                setChecker(row, column, num);
                board[row][column] = num + '0' + 1;
                isValid = conquer(board, nextPos[0], nextPos[1]);
                setChecker(row, column, num);
                if (isValid) {
                    return true;
                }
            }
            board[row][column] = '.';
        }
        return isValid;
    }

    void solveSudoku(vector <vector<char>> &board) {
        row_checker = vector < bitset < 9 >> (9, bitset<9>());
        column_checker = vector < bitset < 9 >> (9, bitset<9>());
        sub_board_checker = vector < bitset < 9 >> (9, bitset<9>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                setChecker(i, j, board[i][j] - '0' - 1);
            }
        }

        conquer(board, 0, 0);
    }
};

class Solution_best {
public:
    vector <bitset<9>> rows;
    vector <bitset<9>> columns;
    vector <vector<bitset < 9>>>
    cells;

    bitset<9> getAvailableNum(int i, int j) {
        return ~(rows[i] | columns[j] | cells[i / 3][j / 3]);
    }

    void fillStatus(int i, int j, int num, bool flag) {
        rows[i][num] = flag ? 1 : 0;
        columns[j][num] = flag ? 1 : 0;
        cells[i / 3][j / 3][num] = flag ? 1 : 0;
    }

    vector<int> selectNext(vector <vector<char>> &board) {
        vector<int> next;
        int minAvailableNumCount = 10;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                bitset<9> bits = getAvailableNum(i, j);
                if (bits.count() > minAvailableNumCount) {
                    continue;
                }
                next = {i, j};
                minAvailableNumCount = bits.count();
            }
        }
        return next;
    }

    bool dfs(vector <vector<char>> &board, int count) {
        if (count == 0) {
            return true;
        }

        for (int num = 0; num < 9; num++) {
            vector<int> next = selectNext(board);
            bitset<9> bits = getAvailableNum(next[0], next[1]);
            if (!bits.test(num)) {
                continue;
            }
            fillStatus(next[0], next[1], num, true);
            board[next[0]][next[1]] = num + '0' + 1;
            if (dfs(board, count - 1)) {
                return true;
            }
            board[next[0]][next[1]] = '.';
            fillStatus(next[0], next[1], num, false);
        }
        return false;
    }

    void solveSudoku(vector <vector<char>> &board) {
        rows = vector < bitset < 9 >> (9, bitset<9>(0));
        columns = vector < bitset < 9 >> (9, bitset<9>(0));
        cells = vector < vector < bitset < 9>>>(3, vector < bitset < 9 >> (3, bitset<9>(0)));
        int count = 0;
        // init the rows, columns and cells, and accumulate how many blank need to fill number
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    count++;
                } else {
                    int num = board[i][j] - '0' - 1;
                    fillStatus(i, j, num, true);
                }
            }
        }
        dfs(board, count);
    }
};