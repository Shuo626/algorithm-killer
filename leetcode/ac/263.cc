#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        return _isUgly(n);
    }

    bool _isUgly(int n) {
        if (n == 2 || n == 3 || n == 5 || n == 1) {
            return true;
        }

        return (((n % 2) == 0 && _isUgly(n / 2)) || ((n % 3) == 0 && _isUgly(n / 3)) || ((n % 5) == 0 && _isUgly(n / 5)));
    }
};