//
// Created by huanyan on 2021/11/19.
//

class Solution {
public:
    int climbStairs(int n) {
        /*
         * dp[n] = dp[n-1] + dp[n-2]
         * dp[0] = 0;
         * dp[1] = 1;
         *
         * l 代表 dp[n-2]
         * r 代表 dp[n-1]
        */
        int answer = 1, l = 1, r = 1;
        for (int i = 2; i <= n; i++) {
            answer = l + r;
            l = r;
            r = answer;
        }
        return answer;
    }

    int climbStairs(int n) {
        /*
         * 滑动数组模型：
         *
         * l      r       answer     n
         * 0      0          1       0
         * 0      1          1       1
         * 1      1          2       2
         * ...   ...        ...     ...
         * x      y         x+y      n
         *
         */
        int answer = 1, l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            l = r;
            r = answer;
            answer = l + r;
        }
        return answer;
    }
};