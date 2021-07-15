#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i++) {
            int j;
            j = sqrt(c - i * i);

            if (i * i + j * j == c) {
                return true;
            }
        }

        return false;
    }
};