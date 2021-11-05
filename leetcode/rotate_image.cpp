//
// Created by huanyan on 2021/11/1.
//

class Solution {
public:
    void rotate(vector <vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix.size() != matrix[0].size()) { return; }
        int nums = matrix.size();
        // represent level
        int times = 0;
        while (times <= (nums >> 1)) {
            int len = nums - (times << 1);
            for (int i = 0; i < len - 1; ++i) {
                int temp = matrix[times][times + i];
                // 每次替换四个数字，分别在四个不同的边上
                // 对于第一个数字A，替换他的数字B，column B = row A, row B = times + len - i - i, 因为是顺时针旋转，行上倒数第 i 行上的数字替换 A
                // len 为本次替换正方形边长，加上 times 意味着补齐前面的空缺， -1 意味着去尾，因为从0开始， -i 意味着算出倒数第几个
                // 生成公式  matrix[times][times + i] = matrix[times + len - i -1][times]
                matrix[times][times + i] = matrix[times + len - i - 1][times];
                matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
                matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
                matrix[times + i][times + len - 1] = temp;
            }
            ++times;
        }
    }
};