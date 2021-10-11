//
// Created by huanyan on 2021/9/8.
//

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string answer;
        int m = num1.size(), n = num2.size();
        vector<int> store(m + n, 0);

        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                store[i + j + 1] = store[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = m + n - 1; i > 0; i--) {
            store[i - 1] = store[i - 1] + store[i] / 10;
            store[i] = store[i] % 10;
        }

        int i = store[0] == 0 ? 1 : 0;
        for (int i = store[0] == 0 ? 1 : 0; i < m + n; i++) {
            char num = store[i] + '0';
            answer = answer + num;
        }

        return answer;
    }
};