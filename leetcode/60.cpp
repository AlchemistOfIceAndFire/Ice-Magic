//
// Created by huanyan on 2021/8/17.
//
class Solution {
public:
    vector<double> dicesProbability(int n) {
        double base = double(1) / double(6);
        vector<double> answer(6, base);

        for (int i = 2; i <= n; i++) {
            vector<double> dp(5 * i + 1, 0);
            for (int j = 0; j < answer.size(); j++) {
                for (int k = 0; k < 6; k++) {
                    dp[j + k] = dp[j + k] + answer[j] * base;
                }
            }
            answer = dp;
        }

        return answer;
    }
};