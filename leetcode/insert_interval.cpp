//
// Created by huanyan on 2021/11/5.
//

/*
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 *
 * nl nr, l r
 *
 * case 1: newInterval in the right for interval without overlap
 *      just add interval to answer
 * case 2: newInterval in the left for interval without overlap
 *      add newInterval to answer firstly, if first to add newInterval
 *      add interval
 * case 3: have overlap need to merge
 *      merge nl l nr r
 *
 * if newInterval in the tail, we need to add it.
 *
 *
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        bool flag = false;
        int nl = newInterval[0], nr = newInterval[1];
        vector <vector<int>> answer;

        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (nl > r) {
                answer.push_back({l, r});
            } else if (nr < l) {
                if (!flag) {
                    answer.push_back({nl, nr});
                    flag = true;
                }
                answer.push_back({l, r});
            } else {
                nl = min(nl, l);
                nr = max(nr, r);
            }
        }

        if (!flag) {
            answer.push_back({nl, nr});
        }

        return answer;
    }
};