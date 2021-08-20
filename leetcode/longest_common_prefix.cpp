//
// Created by huanyan on 2021/8/18.
//

class Solution {
public:
    string longestCommonPrefix(vector <string> &strs) {
        string answer = "";

        // find min size string
        string shortest = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            if (shortest.size() > strs[i].size()) {
                shortest = strs[i];
            }
        }

        for (int i = 0; i < shortest.size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (shortest[i] != strs[j][i]) {
                    return answer;
                }
            }
            answer = answer + shortest[i];
        }
        return answer;
    }
};
