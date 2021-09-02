//
// Created by huanyan on 2021/8/23.
//

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);

        vector<int> dp(str.size());
        dp[0] = 1;

        for (int i = 1; i < str.size(); i++) {
            dp[i] = dp[i - 1];
            if ((str[i - 1] - '0') == 1 || ((str[i - 1] - '0' == 2) && (str[i] - '0') < 6)) {
                int add = i < 2 ? 1 : dp[i - 2];
                dp[i] = dp[i] + add;
            }
        }
        return dp[str.size() - 1];
    }

    int recursion(string s, int i) {
        if (i <= 0) {
            return 1;
        }
        if (i > 0 && s.substr(i - 1, 2) >= "10" && s.substr(i - 1, 2) <= "25") {
            return recursion(s, i - 1) + recursion(s, i - 2);
        } else {
            return recursion(s, i - 1);
        }
    }

    int translateNum(int num) {
        string s = to_string(num);
        return recursion(s, s.size() - 1);
    }
};