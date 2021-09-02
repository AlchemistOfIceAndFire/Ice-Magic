//
// Created by huanyan on 2021/8/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector <string> &answer, string &path, int level, vector <string> &symbols) {
        if (level == symbols.size()) {
            answer.push_back(path);
            return;
        }

        for (int i = 0; i < symbols[level].size(); i++) {
            path.push_back(symbols[level][i]);
            dfs(answer, path, level + 1, symbols);
            path.pop_back();
        }
    }

    vector <string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        map<char, string> dict = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"},
                };

        vector <string> symbols;
        for (int i = 0; i < digits.size(); i++) {
            symbols.push_back(dict[digits[i]]);
        }

        vector <string> answer;
        string s = "";
        dfs(answer, s, 0, symbols);
        return answer;
    }
};