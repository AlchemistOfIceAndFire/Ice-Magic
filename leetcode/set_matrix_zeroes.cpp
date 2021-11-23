//
// Created by huanyan on 2021/11/22.
//

class Solution {
public:
    void setZeroes(vector <vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m), cols(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    continue;
                }
                rows[i] = 1;
                cols[j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroes(vector <vector<int>> &matrix) {
        // use flagCol0 sign the col 0 where have zero
        int m = matrix.size(), n = matrix[0].size(), flagCol0 = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                flagCol0 = 1;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // matrix[0][j] just means the column j have 0, need use 0,0 to sign row 0 whether have 0, so we need to update desc
        // because if 0,0 is zero and update row 0 firstly, some column not zero will be updated to be zero
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (flagCol0) {
                matrix[i][0] = 0;
            }
        }
    }
};