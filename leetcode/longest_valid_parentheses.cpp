//
// Created by huanyan on 2021/10/12.
//

/*
 * vector<int> dp stores the max count in current position who is equal ')'
 * if s[i] == '(', dp[i] = 0
 * if s[i] == ')'
 *      if s[i-1] == '(', dp[i] = dp[i-2] + 2
 *      if s[i-1] == ')', the position i-dp[i-1]-1 match to position i.
 *          if dp[i-1] == 0, continue
 *          if s[i-dp[i-1]-1] == '(', dp[i] = dp[i-1] + 2
 *              if dp[i-dp[i-1]-2] > 0, dp[i] = dp[i] + dp[i-dp[i-dp[i-1]-2]]
 *          if s[i-dp[i-1]-1] == ')', dp[i] = 0
 *
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0, n = s.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                continue;
            }
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0 && dp[i - 2] > 0) {
                        dp[i] = dp[i] + dp[i - 2];
                    }
                } else {
                    if (dp[i - 1] == 0) {
                        continue;
                    }
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0 && dp[i - dp[i - 1] - 2] > 0) {
                            dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};