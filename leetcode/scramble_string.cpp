//
// Created by huanyan on 2021/12/8.
//

/*
 * boundary return cases:
 * if visited
 * if sub(s1) -eq sub(s2)
 *
 * true cases:
 * if l_s1 -eq l_s2 && r_s1 -eq r_s2
 * if l_s1 -eq r_s2 && r_s1 -eq l_s2
 *
 * false cases:
 * if each char count of s1 -nq each cahr count of s2
 *
 * because if s1 match to s2, the length of s1 and s3 must are equal
 *
 * in order case
 * s1:
 *  ---------------
 *  |    |        |
 *  --k---len-k---
 *  start at index i
 * s2:
 *  ---------------
 *  |    |        |
 *  --k---len-k---
 *  start at index j
 *
 *  dp[i][j][k] && dp[i+k][j+k][len-k]
 *
 * not in order case
 * s1:
 *  ---------------
 *  |    |        |
 *  --k---len-k---
 *  start at index i
 * s2:
 *  ---------------
 *  |        |    |
 *  --len-k----k---
 *  start at index j
 *
 *  dp[i][j+len-k][k] && dp[i+k][j][len-k]
 *
 */

class Solution {
private:
    vector <vector<vector < int>> dp;
    string s1, s2;
public:
    //------------------------store in memory and searching------------------------------------
    bool checkCount(string _s1, string _s2) {
        map<int, int> cnt;
        for (auto c: _s1) {
            cnt[c - 'a']++;
        }
        for (auto c: _s2) {
            cnt[c - 'a']--;
        }
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            if (iter->second != 0) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int i, int j, int length) {
        if (dp[i][j][length]) {
            return dp[i][j][length] == 1;
        }

        string _s1 = s1.substr(i, length), _s2 = s2.substr(j, length);
        if (_s1 == _s2) {
            dp[i][j][length] = 1;
            return true;
        }

        if (!checkCount(_s1, _s2)) {
            dp[i][j][length] = -1;
            return false;
        }

        for (int k = 1; k < length; k++) {
            // judge in order
            if (dfs(i, j, k) && dfs(i + k, j + k, length - k)) {
                dp[i][j][length] = 1;
                return true;
            }

            // judge not in order
            if (dfs(i, j + length - k, k) && dfs(i + k, j, length - k)) {
                dp[i][j][length] = 1;
                return true;
            }
        }
        dp[i][j][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }

        this->s1 = s1;
        this->s2 = s2;
        int n = s1.size();
        dp.resize(n, vector < vector < int >> (n, vector<int>(n + 1)));

        return dfs(0, 0, n);
    }

    //------------------------dp------------------------------------
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        int n = s1.size();
        vector < vector < vector < int>>> dp(n, vector < vector < int >> (n, vector<int>(n + 1, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][1] = 1;
                }
            }
        }

        for (int length = 2; length <= n; length++) {
            // i + length <=n, because for length, the idx from i to i+length-1
            for (int i = 0; i + length <= n; i++) {
                // j + length <=n, because for length, the idx from j to j+length-1
                for (int j = 0; j + length <= n; j++) {
                    for (int k = 1; k < length; k++) {
                        bool in_order = dp[i][j][k] && dp[i + k][j + k][length - k];
                        bool swap_order = dp[i][j + length - k][k] && dp[i + k][j][length - k];
                        if (in_order || swap_order) {
                            dp[i][j][length] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};