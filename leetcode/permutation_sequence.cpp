//
// Created by huanyan on 2021/11/11.
//

class Solution {
public:
    void dfs(string &answer, vector<bool> &visited, vector<int> &factorials, int n, int k) {
        if (answer.size() == n) {
            return;
        }

        int factorial = factorials[n - 1 - answer.size()];
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            if (factorial < k) {
                k = k - factorial;
                continue;
            }
            visited[i] = true;
            answer.push_back(i + '0');
            dfs(answer, visited, factorials, n, k);
            return;
        }
    }

    string getPermutation(int n, int k) {
        string answer = "";
        vector<bool> visited(n);
        vector<int> factorials(n);

        factorials[0] = 1;
        for (int i = 1; i < n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        dfs(answer, visited, factorials, n, k);

        return answer;
    }
};