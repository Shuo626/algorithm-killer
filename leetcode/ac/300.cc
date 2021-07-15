#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        dp.push_back(1);

        for (int i = 1; i < nums.size(); i++) {
            int maxSubLen;

            maxSubLen = 0;
            
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxSubLen = max(maxSubLen, dp[j]);
                }
            }

            dp.push_back(maxSubLen + 1);
        }


        int ans;
        
        ans = 0;

        for (int& len: dp) {
            ans = max(ans, len);
        }

        return ans;
    }
};