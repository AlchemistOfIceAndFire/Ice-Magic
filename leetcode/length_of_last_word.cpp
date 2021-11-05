//
// Created by huanyan on 2021/11/5.
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0, idx = s.size() - 1;
        while (s[idx] == ' ') {
            idx--;
        }

        while (idx >= 0 && s[idx] != ' ') {
            answer++;
            idx--;
        }

        return answer;
    }
};