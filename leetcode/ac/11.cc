#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r;
        l = 0;
        r = height.size() - 1;

        int result;
        result = 0;

        while (l < r) {
            result = max(result, (r - l) * min(height[l], height[r]));

            if (height[l] < height[r]) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return result;
    }
};