//
// Created by huanyan on 2021/11/29.
//

/*
 * main thing, for the index i, find it the nearest left board that less than heights[i], and find the nearest right board that less than heights[i],
 * so the right board - left board - 1 is the width for heights[i]
 *
 * use the monotonous stack to find the left and right board.
 * if the stack.top more than heights[i] means need to pop it, because it can calculate in heights[i] rectangle
 *
 * if the stack.top less than heights[i] meas you find the left board for heights[i].(you can use this function to find the left and right board in two arrays)
 * And in this case, the i is the right board for stack.top, and the stack.pop.pop is the left board for stack.pop.(you can use it to calculate the area of stack.top)
 *
 * And you can use the guard node to avoid judging of stack empty.
 */

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

        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[i] < heights[mono_stack.top()]) {
                int height = heights[mono_stack.top()];
                mono_stack.pop();

                int width = i;
                if (!mono_stack.empty()) {
                    width -= mono_stack.top() + 1;
                }

                answer = max(answer, height * width);
            }
            mono_stack.push(i);
        }

        while (!mono_stack.empty()) {
            int height = heights[mono_stack.top()];
            mono_stack.pop();

            int width = n;
            if (!mono_stack.empty()) {
                width -= mono_stack.top() + 1;
            }

            answer = max(answer, height * width);
        }

        return answer;
    }

    int largestRectangleArea(vector<int> &heights) {
        int answer = 0, n = heights.size();
        stack<int> mono_stack;

        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[i] < heights[mono_stack.top()]) {
                int height = heights[mono_stack.top()];
                mono_stack.pop();

                int left = mono_stack.empty() ? -1 : mono_stack.top();
                int right = i;
                answer = max(answer, (right - left - 1) * height);
            }
            mono_stack.push(i);
        }

        while (!mono_stack.empty()) {
            int height = heights[mono_stack.top()];
            mono_stack.pop();

            int left = mono_stack.empty() ? -1 : mono_stack.top();
            int right = n;
            answer = max(answer, (right - left - 1) * height);
        }

        return answer;
    }

    int largestRectangleArea(vector<int> &heights) {
        stack<int> mono_stack;
        mono_stack.push(0);

        vector<int> _heights = {0};
        _heights.insert(_heights.end(), heights.begin(), heights.end());
        _heights.push_back({0});

        int answer = 0, n = _heights.size();

        for (int i = 1; i < n; i++) {
            while (_heights[i] < _heights[mono_stack.top()]) {
                int height = _heights[mono_stack.top()];
                mono_stack.pop();
                int width = i - mono_stack.top() - 1;
                answer = max(answer, height * width);
            }
            mono_stack.push(i);
        }

        return answer;
    }
};