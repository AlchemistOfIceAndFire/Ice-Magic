//
// Created by huanyan on 2021/12/9.
//
class Solution {
private:
    int IP_SEG_COUNT = 4;
    int IP_BIT_COUNT = 3;
public:
    void dfs(vector <string> &answer, vector <string> &path, string &s, int begin, int end) {
        if (begin == end && path.size() == 4) {
            string ss = path[0];
            for (int i = 1; i < path.size(); i++) {
                ss.append(".");
                ss.append(path[i]);
            }
            answer.push_back(ss);
            return;
        }

        if (path.size() == 4 || begin == end) {
            return;
        }

        for (int i = begin; i < begin + 3 && i < end; i++) {
            string temp = s.substr(begin, i - begin + 1);
            if ((temp.size() > 1 && temp[0] == '0') || stoi(temp) > 255) {
                break;
            }
            path.push_back(temp);
            dfs(answer, path, s, i + 1, end);
            path.pop_back();
        }
    }

    vector <string> restoreIpAddresses(string s) {
        vector <string> answer, path;
        dfs(answer, path, s, 0, s.length());
        return answer;
    }

    void dfs(vector <string> &answer, vector<int> &path, string &s, int begin, int end) {
        if (begin == end && path.size() == IP_SEG_COUNT) {
            string ss = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                ss.append(".");
                ss.append(to_string(path[i]));
            }
            answer.push_back(ss);
            return;
        }

        if (path.size() == 4 || begin == end) {
            return;
        }

        int ip_addr = 0;
        for (int i = begin; i < begin + IP_BIT_COUNT && i < end; i++) {
            ip_addr = ip_addr * 10 + (s[i] - '0');
            if (ip_addr > 255 || (i - begin + 1 > 1 && ip_addr < 10)) {
                return;
            }
            path.push_back(ip_addr);
            dfs(answer, path, s, i + 1, end);
            path.pop_back();
        }
    }

    vector <string> restoreIpAddresses(string s) {
        vector <string> answer;
        vector<int> path;
        dfs(answer, path, s, 0, s.length());
        return answer;
    }

};