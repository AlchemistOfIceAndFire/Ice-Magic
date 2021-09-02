//
// Created by huanyan on 2021/9/1.
//

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 转型 long 避免 int 值溢出，int 最小负数转换为 int 正数会溢出
        long _dividend = long(dividend), _divisor = long(divisor);

        // 用于返回结果是正数还是负数
        long sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;

        // 转换为正数
        _dividend = _dividend < 0 ? -_dividend : _dividend;
        _divisor = _divisor < 0 ? -_divisor : _divisor;
        // answer 用来存储累次数, sum 用来存储当前累加值, left 用于累加进化或退化, base 用于存储当前累加时的增量
        long answer = 0, sum = 0, left = 1, base = _divisor;

        // 考虑特殊情况
        if (_dividend < _divisor) {
            return 0;
        }

        // 如果 base < _divisor 说明已经退无可退，最基础的 _divisor 也会导致溢出说明循环已经完成
        while (true) {
            sum = sum + base;
            answer = answer + left;
            left = left << 1;
            base = base << 1;

            // 如果下一次sum + 增量超出 _dividend， 则需要进行增量的退化，如果退到小于 _divisor 说明无法再退了，循环结束
            while (sum > _dividend - base && base >= _divisor) {
                left = left >> 1;
                base = base >> 1;
            }

            if (base < _divisor) {
                break;
            }
        }

        if (sign == 1 && answer > INT32_MAX) {
            return INT32_MAX;
        }

        if (sign == -1 && -answer < INT32_MIN) {
            return INT32_MIN;
        }

        return sign < 0 ? -answer : answer;
    }
};