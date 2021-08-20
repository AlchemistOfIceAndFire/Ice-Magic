//
// Created by huanyan on 2021/8/12.
//

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        string answer = "";
        for (int i = 0; i < numRows; i++) {
            vector<int> jumps(2);
            if (i == 0 || i == numRows - 1) {
                jumps = {2 * numRows - 2, 2 * numRows - 2};
            } else {
                jumps = {2 * (numRows - i) - 2, 2 * i};
            }

            int j = i, jump = 0;
            while (j < s.size()) {
                answer += s[j];
                j += jumps[jump];
                jump ^= 1;
            }
        }
        return answer;
    }

    string convertUpDown(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        vector <string> results(numRows, "");
        int row = 0, direction = -1;

        for (int i = 0; i < s.size(); i++) {
            results[row] += s[i];
            direction = row == 0 || row == numRows - 1 ? -direction : direction;
            row += direction;
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            result += results[i];
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)