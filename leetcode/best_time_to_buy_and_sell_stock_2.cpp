//
// Created by huanyan on 2021/12/20.
//

/*
 * dp_keep[] represents in day i, the max profit when we keep stock
 * dp_sell[] represents in day i, the max profit when we sell our stock
 *
 * so in day i,
 * dp_keep[i] = max(dp_keep[i-1], dp_sell[i-1] - prices[i])
 * dp_sell[i] = max(dp_sell[i-1], dp_keep[i-1] + prices[i])
 *
 */

/*
 * li represents buy stock in day i.
 * ri represents sell stock in day j.
 *
 * so max_profit = multiple prices[rj] - prices[li]
 * prices[rj] - prices[li] = prices[li+1] - prices[li] + prices[li+2] - prices[li+1] ...
 * \sum_{i=1}^{x} a[l_i+1]-a[l_i]
 *
 *
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp_keep(n), dp_sell(n);
        dp_keep[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp_keep[i] = max(dp_keep[i - 1], dp_sell[i - 1] - prices[i]);
            dp_sell[i] = max(dp_sell[i - 1], dp_keep[i - 1] + prices[i]);
        }

        return dp_sell[n - 1];
    }

    int maxProfit(vector<int> &prices) {
        int answer = 0, n = prices.size();
        for (int i = 1; i < n; i++) {
            answer += max(0, prices[i] - prices[i - 1]);
        }
        return answer;
    }
};