//
// Created by huanyan on 2021/8/15.
//

/*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
*
* if s[i] = p[j] || p[j] == '.' means match
* dp[i][j] means from 0~i in s match to p from 0~j
        * dp[0][0] == true, because null str matches to null p.
* so, i = s/p index + 1
*
* hypothesis: i-1 is current index in s, j-1 is current index in p
* if s[i-1] == p[j-1] or p[j-1] = '.':
*      dp[i][j] = dp[i-1][j-1]
*
* if p[j-1] == '*', it means we need to observe the index before j-1
*      cases:
*      * represent zero
 *         satisify this case need  :
 *         (s[i-1] != p[j-2] and p[j-2] != '.')  -> e.g. aaa aaab*
 *         (s[i-1] == p[j-2] or p[j-2] == '.')   -> e.g. aaab aaabb*
*          dp[i][j] = dp[i][j-2]
*      * represent once s[i-1] == p[j-2] or p[j-2] == '.':
*          aaab aaab*b*
*          dp[i][j] = dp[i-1][j-2]
*      * represent more than once:
*          aaabbb aaab*  satisfy this case need s[i-1] == p[j-2] or p[j-2] == '.'
*          dp[i][j] = dp[i-1][j]
 *
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j) {
            if (i < 0 || j < 0) {
                return false;
            }
            return s[i] == p[j] || p[j] == '.';
        };

        int m = s.size(), n = p.size();
        vector <vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // why we need iterate the s from 0, because may be s is null str, or the p some char make these chars appear zero time.
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
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