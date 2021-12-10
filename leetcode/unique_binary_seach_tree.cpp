//
// Created by huanyan on 2021/12/10.
//

/*
* G(n) means the count of using 1..n to generate bst
* F(i,n) means the count of using 1 .. n to generate bst and use the i to be a root
*
* so G(n) = F(1,n) + F(2,n) + F(3,n) + ... + F(n,n)
*    F(i,n) = G(i-1) * G(n-i)
*
* so Gn(n) = ∑{i=1,n} G(i-1) * G(n-i)
*
*
*
*
*/

class Solution {
public:
    int dfs(int begin, int end) {
        if (begin > end) {
            return 1;
        }

        int cnt = 0;
        for (int i = begin; i <= end; i++) {
            int l_cnt = dfs(begin, i - 1);
            int r_cnt = dfs(i + 1, end);
            cnt += (l_cnt * r_cnt);
        }

        return cnt;
    }

    int numTrees(int n) {
        return n == 0 ? 0 : dfs(1, n);
    }


    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};