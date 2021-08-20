//
// Created by huanyan on 2021/8/17.
//


class Solution {
public:
    int lastRemaining(int n, int m) {
        int answer = 0;
        for (int i = 2; i <= m; i++) {
            answer = (answer +m) % 2;
        }
        return answer;
    }
};