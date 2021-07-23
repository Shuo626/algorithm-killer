#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(55);

        for (vector<int>& range: ranges) {
            diff[range[0]] += 1;
            diff[range[1] + 1] -= 1;
        }

        for (int i = 2; i <= right; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = left; i <= right; i++) {
            if (diff[i] <= 0) {
                return false;
            }
        }

        return true;
    }
};