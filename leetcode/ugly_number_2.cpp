//
// Created by huanyan on 2021/8/20.
//


/*
 *  dp[1] = 1
 *  dp[2] = min(1*2, 1*3, 1*5) = 2 p2++ = 2
 *  dp[3] = min (2*2, 1*3, 1*5) = 3 p3++= 2
 *  dp[4] = min(1*5, 2*2, 2*3) = 4 p2++=3
 *  dp[5] = min(1*5, 3*2, 2 * 3) = 5, p5++=2
 *  dp[6] = min(3*2, 2 * 3, 2*5)
 *
 */


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2) {
                p2++;
            }
            if (dp[i] == dp[p3] * 3) {
                p3++;
            }
            if (dp[i] == dp[p5] * 5) {
                p5++;
            }
        }

        return dp[n - 1];
    }

    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        unordered_set<long> visited;
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1L);

        for (int i = 1; i < n; i++) {
            long heap = q.top();
            q.pop();

            for (int j = 0; j < factors.size(); j++) {
                long num = heap * factors[j];
                if (visited.count(num) > 0) {
                    continue;
                }
                visited.insert(num);
                q.push(num);
            }
        }
        return (int) q.top();
    }
};