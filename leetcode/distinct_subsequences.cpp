//
// Created by huanyan on 2021/12/21.
//

/*
 * dp[i][j] means the number of subsequence for s from 0 to i that match to the t from 0 to j
 * the 0 means nothing
 *
 * int m = s.size(), n = t.size();
 *
 * consider the boundary cases:
 * when j = 0, dp[x][0] = 1
 * when i = 0, dp[0][x] = 0
 *
 * consider the normal cases:
 * if s[i] == t[j], we have to choices:
 *      one choice is the s[i] match to t[j], so in this case, dp[i+1][j+1] = dp[i][j]
 *      another choice is the s[i] not match to t[j], so in this case, we need use the s[i-1] to match t[j], dp[i+1][j+1] = dp[i][j+1]
 *      so dp[i+1][j+1] = dp[i][j] + dp[i][j+1]
 * if s[i] != t[j], we just have one choice:
 *      we need use the s[i-1] to match t[j], so dp[i+1][j+1] = dp[i][j+1]
 *
 * because just when m >= n, the s can have the subsequences of t, so we iterate the s firstly.
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) {
            return 0;
        }

        vector <vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] += dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};