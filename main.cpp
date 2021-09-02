//
// Created by huanyan on 2021/8/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <leetcode/model.cpp>
#include <math.h>

using namespace std;

int divide(int dividend, int divisor) {
    long _dividend = long(dividend), _divisor = long(divisor);
    long sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -1 : 1;
    _dividend = _dividend < 0 ? -_dividend : _dividend;
    _divisor = _divisor < 0 ? -_divisor : _divisor;
    long answer = 0, sum = 0, left = 1, base = _divisor;

    if (_dividend < _divisor) {
        return 0;
    }
    if (_dividend == _divisor) {
        return sign;
    }

    while (base >= _divisor && sum < _dividend) {
        sum = sum + base;
        answer = answer + left;
        left = left << 1;
        base = base << 1;

        while (left > 0 && sum > _dividend - base) {
            left = left >> 1;
            base = base >> 1;
        }
    }

    if (sign == 1 && answer * sign > INT32_MAX) {
        return INT32_MAX;
    }

    if (sign == -1 && answer * sign < INT32_MIN) {
        return INT32_MIN;
    }

    return sign < 0 ? -answer : answer;
}

int main() {
    cout << divide(8, 3) << endl;
    cout << (1 >> 1) << endl;
}



