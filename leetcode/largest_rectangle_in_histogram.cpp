//
// Created by huanyan on 2021/11/29.
//

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int answer = 0, n = heights.size();
        vector<int> lefts(n), rights(n);

        // find the nearest height index on the left that less than heights[i] as the left board
        stack<int> mono_stack;
        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            lefts[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        // find the nearest height index on the right that less than heights[i] as the right board
        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            rights[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        for (int i = 0; i < n; i++) {
            answer = max(answer, (rights[i] - lefts[i] - 1) * heights[i]);
        }

        return answer;
    }

    int largestRectangleArea(vector<int> &heights) {
        int answer = 0, n = heights.size();
        vector<int> lefts(n, 0), rights(n, n);
        stack<int> mono_stack;

        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                rights[mono_stack.top()] = i;
                mono_stack.pop();
            }
            lefts[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        for (int i = 0; i < n; i++) {
            answer = max(answer, heights[i] * (rights[i] - lefts[i] - 1));
        }

        return answer;
    }

    int largestRectangleArea(vector<int> &heights) {
        int answer = 0, n = heights.size();
        stack<int> mono_stack;


    }

};