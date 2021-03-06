//
// Created by huanyan on 2021/11/23.
//

class Solution {
public:
    bool check(map<char, int> &s_cnt, map<char, int> &t_cnt) {
        for (auto iter = t_cnt.begin(); iter != t_cnt.end(); iter++) {
            if (s_cnt[iter->first] < iter->second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        map<char, int> s_cnt, t_cnt;
        for (int i = 0; i < t.size(); i++) {
            t_cnt[t[i]]++;
        }

        int ans_l = -1, len = INT32_MAX;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (t_cnt.count(s[r]) > 0) {
                s_cnt[s[r]]++;
            }

            // if find the sub str of s satisfy to t, then consider move the l
            while (check(s_cnt, t_cnt) && l <= r) {
                // store the minimum answer
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ans_l = l;
                }

                // subtract the counter when you need to move the l
                if (t_cnt.count(s[l]) > 0) {
                    s_cnt[s[l]]--;
                }
                // move the l
                l++;
            }
        }
        return ans_l == -1 ? string() : s.substr(ans_l, len);
    }
};