//
// Created by huanyan on 2021/8/24.
//

class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) {
            return 0;
        }
        long left = 1, level = 1;

        while (n > 0) {
            long bit_count = 9 * level * left;

            if (n - bit_count <= 0) {
                break;
            }

            n = n - bit_count;
            level = level + 1;
            left = left * 10;
        }

        long num_position = n % level == 0 ? n / level : n / level + 1;
        int bit_position = n % level;

        long num = left + num_position - 1;

        if (bit_position == 0) {
            return num % 10;
        }

        long answer = 0;
        for (int i = level; i >= bit_position; i--) {
            answer = num % 10;
            num = num / 10;
        }
        return int(answer);
    }
};
