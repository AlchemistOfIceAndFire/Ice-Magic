//
// Created by huanyan on 2021/8/30.
//

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
                        cout << i << endl;
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