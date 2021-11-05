//
// Created by huanyan on 2021/11/2.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string>> dict;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            dict[key].push_back(strs[i]);
        }

        vector<vector<string>> answer();
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
            answer.push_back(iter->second);
        }

        return answer;
    }
};