//
// Created by huanyan on 2021/12/9.
//

/*
 * n=0,  0
 * n=1,  0  1
 * n=2,  00  01 11 10
 * n=3,  000 001 011 010 --- 110 111 101 100
 *
 * Gn(n+1) = G'(n) U R'(n)
 *
 * G'(n) is add zero in front of each element in G(n), so G(n) is equal to G'(n).
 * R'(n) is reverse the G(n) elements, and add the one in front of each element.
 *
 * find the rule, in each answer, such as n=3, because of the left half of answer and the right half of answer are symmetrical when we ignore the highest bit of binary.
 * so for the right half part, we just need to add one on the highest bit of binary.
 * becasue in the left half part each adjacent pair is deffer exactly one bit, so for the right half part, we add one to the highest bit, can always require this requirement.
 *
 * why we need to add 1 to the highest bit, because if need to avoid carry over.
 *
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer(1, 0);
        int head = 1;

        for (int i = 0; i < n; i++) {
            for (int j = answer.size() - 1; j >= 0; j--) {
                answer.push_back(answer[j] + head);
            }
            head <<= 1;
        }

        return answer;
    }
};