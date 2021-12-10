//
// Created by huanyan on 2021/12/9.
//

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    int numDecodings(string s) {
        int n = s.size(), f1 = 1, f2 = 1, answer = 0;
        for (int i = 0; i < n; i++) {
            answer = 0;
            if (s[i] != '0') {
                answer += f1;
            }
            if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)) {
                answer += f2;
            }
            f2 = f1;
            f1 = answer;
        }
        return answer;
    }
};