//
// Created by huanyan on 2021/11/22.
//

class Solution {
public:
    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = m - 1; i >= 0; i--) {
            if (target < matrix[i][0]) {
                continue;
            }
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            break;
        }
        return false;
    }

    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, bottom = m - 1, row = -1;
        while (up < bottom) {
            // upon to get mid avoid dead while
            int mid = (up + bottom + 1) / 2;
            if (matrix[mid][0] <= target) {
                up = mid;
            } else if (matrix[mid][0] > target) {
                bottom = mid - 1;
            }
        }
        row = up;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};