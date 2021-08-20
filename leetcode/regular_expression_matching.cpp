//
// Created by huanyan on 2021/8/15.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j) {
            if (i < 0) {
                return false;
            }
            return s[i] == p[j] || p[j] == '.';
        };

        int m = s.size(), n = p.size();
        vector <vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j - 1] == '*') {
                    if (match(i - 1, j - 2)) {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                } else {
                    if (match(i - 1, j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};