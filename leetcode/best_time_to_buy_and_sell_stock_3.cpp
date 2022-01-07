//
// Created by huanyan on 2021/12/20.
//

class Solution {
public:
    // while the asc order exit, we have the chance to make profit, so we need to find the first asc order make profit
    int maxProfit(vector<int> &prices) {
        int buy_1 = -prices[0], buy_2 = -prices[0], sell_1 = 0, sell_2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy_1 = max(buy_1, -prices[i]);
            sell_1 = max(sell_1, buy_1 + prices[i]);

            buy_2 = max(buy_2, sell_1 - prices[i]);
            sell_2 = max(sell_2, buy_2 + prices[i]);
        }
        return sell_2;
    }

    int maxProfit(vector<int> &prices) {
        /*
         * dp[i][j][k], i represents day i, j represents 0:sell or 1:buy, k represents transaction times
         * dp[i][0][0] = 0
         *
         * max_profit in day i and not keep stock, and sell once
         * dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0] + prices[i])
         *
         * max profit in day i and not keep stock, and sell twice
         * dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][1] + prices[i])
         *
         * max profit in day i and keep stock, and sell zero time
         * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0] - prices[i])
         *
         * max profit in day i and keep stock, and sell once
         * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1] - prices[i])
         *
         * max profit in day i and keep stock and sell twice, this case is invalid, need to set it to INT_MIN to avoid max function choose it
         * dp[i][1][2] = invalid
         *
         */

        int n = prices.size();
        vector < vector < vector < long>> > dp(n, vector < vector < long >> (2, vector<long>(3, 0)));
        dp[0][0][0] = 0;
        dp[0][1][0] = -prices[0];
        dp[0][0][1] = INT_MIN;
        dp[0][0][2] = INT_MIN;
        dp[0][1][1] = INT_MIN;
        dp[0][1][2] = INT_MIN;
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
            dp[i][1][2] = INT_MIN;
        }
        return max(dp[0][0][0], max(dp[n - 1][0][1], dp[n - 1][0][2]));
    }
};