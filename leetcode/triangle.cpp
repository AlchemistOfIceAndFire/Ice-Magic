//
// Created by huanyan on 2021/12/24.
//

class Solution {
public:
    int dfs(vector <vector<int>> &triangle, int sum, int level, int begin, int end) {
        if (level == triangle.size()) {
            return sum;
        }

        int n = triangle[level].size(), answer = INT_MAX;
        for (int i = begin; i < end; i++) {
            int _sum = sum + triangle[level][i];
            answer = min(answer, dfs(triangle, _sum, level + 1, i, i + 2));
        }
        return answer;
    }

    int minimumTotal(vector <vector<int>> &triangle) {
        return dfs(triangle, 0, 0, 0, 1);
    }

    int minimumTotal(vector <vector<int>> &triangle) {
        int n = triangle.size();
        vector <vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1);
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        int answer = INT_MAX;
        for (int i = 0; i < dp[n - 1].size(); i++) {
            answer = min(answer, dp[n - 1][i]);
        }
        return answer;
    }
};