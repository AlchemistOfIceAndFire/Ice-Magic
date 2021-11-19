//
// Created by huanyan on 2021/11/11.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector <vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] += i > 0 ? dp[i - 1][j] : 0;
                    dp[i][j] += j > 0 ? dp[i][j - 1] : 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};