#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans, curSum;

        ans = INT_MIN;

        curSum = 0;

        for (int& num: nums) {
            curSum += num;
            ans = max(ans, curSum);

            if (curSum < 0) {
                curSum = 0;
            }
        }

        return ans;
    }
};