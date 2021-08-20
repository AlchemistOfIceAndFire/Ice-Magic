//
// Created by huanyan on 2021/8/12.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dict;
        int l = 0, max = 0;
        for (int r = 0; r < s.size(); r++) {
            if (dict.count(s[r]) > 0) {
                l = l <= dict[s[r]] ? dict[s[r]] + 1 : l;
            }
            dict[s[r]] = r;
            max = r - l + 1 > max ? r - l + 1 : max;
        }
        return max;
    }
};