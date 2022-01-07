//
// Created by huanyan on 2021/12/20.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_cost = INT_MAX, max_profit = 0, n = prices.size();
        for (int i = 0; i < n; i++) {
            min_cost = min(min_cost, prices[i]);
            max_profit = max(max_profit, prices[i] - min_cost);
        }
        return max_profit;
    }
};