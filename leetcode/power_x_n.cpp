//
// Created by huanyan on 2021/9/26.
//

/*
 * solution 1:
 * 2^10
 * 2^10 = 2^5 * 2^5
 * 2^5 = 2^2 * 2^2 * 2
 * 2^2 = 2^1 * 2^1
 * 2^1 = 2^0 * 2
 *
 *
 * x^n = x^n * res
 * x^n = x^0 * res
 *
 * res = 1
 * n = 10, (2*2)^5 * 1
 * n = 5,  (4*4)^2 * 1 * 4
 * n = 2,  (16*16)^1 * 1 * 4
 * n = 1,  (256*256)^0 * 1 * 4 * 256
 *
 * res = 1
 * n = 5, (3*3)^2 * 1 * 3
 * n = 2, (9*9)^1 * 1 * 3
 * n = 1, (81*81)^0 * 1 * 3 * 81
 *
 */

class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1.0;
        long _n = long(n);
        if (_n < 0) {
            x = 1 / x;
            _n = -_n;
        }

        while (_n > 0) {
            if (_n % 2 == 1) {
                answer = answer * x;
            }
            x = x * x;
            _n = _n / 2;
        }

        return answer;
    }

    double myPow(double x, int n) {
        double answer = 1.0;
        long _n = long(n);
        _n = n > 0 ? _n : -_n;

        while (_n > 0) {
            if ((_n & 1) == 1) {
                answer = answer * x;
            }
            x = x * x;
            _n = _n >> 1;
        }
        return n > 0 ? answer : 1 / answer;
    }
};
