#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp, pre;

        dp.push_back(1);
        pre.push_back(-1);

        for (int i = 1; i < nums.size(); i++) {
            int maxLen, index;

            maxLen = 0;
            index = -1;

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] > maxLen) {
                        maxLen = dp[j];
                        index = j;
                    }
                }
            }

            dp.push_back(maxLen + 1);
            pre.push_back(index);
        }

        vector<int> ans;
        int lastIndex, maxLen;

        maxLen = 0;

        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        while (lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = pre[lastIndex];
        }

        return ans;
    }
};