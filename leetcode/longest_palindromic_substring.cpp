//
// Created by huanyan on 2021/8/12.
//

class Solution {
public:
    string longestPalindromeDp(string s) {
        /*
         * dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
         *
         */
        vector <vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // init the dp array, single char always is palindromic
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }

        int max = 1, left = 0;
        for (int r = 1; r < s.size(); r++) {
            for (int l = 0; l < r; l++) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;

                    if (r - l + 1 > max) {
                        max = r - l + 1;
                        left = l;
                    }
                }
            }
        }

        return s.substr(left, max);
    }

    string longestPalindrome(string s) {
        int max = 1, left = 0, length = 1;
        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;

            while (r < s.size() && s[i] == s[r]) {
                r = r + 1;
                length += 1;
            }

            while (l > -1 && r < s.size() && s[l] == s[r]) {
                l = l - 1;
                r = r + 1;
                length += 2;
            }

            if (length > max) {
                max = length;
                left = l + 1;
            };

            length = 1;
        }
        return s.substr(left, max);
    }
};