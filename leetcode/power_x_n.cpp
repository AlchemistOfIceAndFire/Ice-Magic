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
 * n = 10, 4^5 * 1
 * n = 5,  16^2 * 1 * 4
 * n = 2,  256^1 * 1 * 4
 * n = 1,  65536^0 * 1 * 4 * 256
 *
 * res = 1
 * n = 5, 9^2 * 1 * 3
 * n = 2, 81^1 * 1 * 3
 * n = 1, 6561^0 * 1 * 3 * 81
 *
 *
 * solution 2:
 *
 * 10: n = 2: bm bm-1 bm-2 ... b3 b2 b1
 * x = 2^0 * b1 + 2^1 * b2 + 2^2 * b3 + ... + 2^m-1 * bm
 *
 * x^n = x^(2^0 * b1 + 2^1 * b2 + 2^2 * b3 + ... + 2^m-1 * bm)
 * x^n = x^(2^0 * b1) * x^(2^1 * b2) * .... * x^(2^m-1 * bm)
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
