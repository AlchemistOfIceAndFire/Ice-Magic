//
// Created by huanyan on 2021/11/22.
//

/*
 * if word1[i] == words[j]
 *      dp[i][j] = dp[i-1][j-1;
 * else
 *      case1: insert, dp[i][j] = dp[i][j-1] + 1
 *      case2: delete, dp[i][j] = dp[i-1][j] + 1
 *      case3: replace, dp[i][j] = dp[i-1][j-1] + 1
 *
 * avoid to handle the board cases, need to init the dp vector
 * index 0 means null str ''
 *
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector <vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};