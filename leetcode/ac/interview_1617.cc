#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            dp.push_back(max(dp[i - 1] + nums[i], nums[i]));
        }

        return findMax(dp);
    }

    int findMax(vector<int>& nums) {
        int maxNum = -0x7fffffff;

        for (int i = 0; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
        }

        return maxNum;
    }

};
