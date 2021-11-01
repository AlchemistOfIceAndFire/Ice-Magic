//
// Created by huanyan on 2021/10/22.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j) {
            if (i < 0 || j < 0) {
                return false;
            }
            return s[i] == p[j] || p[j] == '?';
        };

        int m = s.size(), n = p.size();
        vector <vector<bool >> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            if (p[i - 1] != '*') {
                break;
            }
            dp[0][i] = true;
        }


        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << i << " " << j << endl;
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
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