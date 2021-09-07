//
// Created by huanyan on 2021/8/30.
//

/*
 * The derivation process of dp
 *
 * n=0, ""
 * n=1, ()
 * n=2, (()) ()()
 * n=3, (())() (()()) ((()))
 *
 * n=n, 可以理解为第n的括号，与 n-1 结果的组合，组合的方式们可以是放在放在括号内，也可以是放在括号两边，但是n-1可以进行拆分，所有可以只考虑放在一侧的情况，避免多一次的拆分
 *
 * dp[n] = ( + dp[i] + ) + dp[n-1-i]
 *
 */

class Solution {
public:
    vector <string> generateParenthesis(int n) {
        vector <vector<string>> dp(n + 1, vector<string>(0));
        dp[0].push_back("");
        dp[1].push_back("()");

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < dp[j].size(); k++) {
                    for (int l = 0; l < dp[i - j - 1].size(); l++) {
                        dp[i].push_back('(' + dp[j][k] + ')' + dp[i - j - 1][l]);
                    }
                }
            }
        }
        return dp[n];
    }

    vector <string> generateParenthesis(int n) {
        vector <vector<string>> dp(n + 1, vector<string>(0));
        dp[0].push_back("");
        dp[1].push_back("()");

        for (int i = 2; i <= n; i++) {
            int l = 0, r = i - 1;
            while (r > -1) {
                for (int j = 0; j < dp[l].size(); j++) {
                    for (int k = 0; k < dp[r].size(); k++) {
                        dp[i].push_back('(' + dp[l][j] + ')' + dp[r][k]);
                    }
                }
                l++;
                r--;
            }
        }
        return dp[n];
    }
};