#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a, b;
        a = b = 0;

        for (int& num: nums) {
            int tmp_a, tmp_b;

            tmp_a = (~a & b & num) | (a & ~b & ~num);
            tmp_b = ~a & (b^num);

            a = tmp_a;
            b = tmp_b;
        }

        return b;
    }
};