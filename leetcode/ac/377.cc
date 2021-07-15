#include <bits/stdc++.h>


using namespace std;


class Solution0 {
public:
    int ans;


    Solution0(): ans(0) {}


    int combinationSum4(vector<int>& nums, int target) {

    }


    void dfs(vector<int>& nums, int target) {
        if (target == 0) {
            ans += 1;
            return;
        }

        for (int& num: nums) {
            if (target - num < 0) {
                continue;
            } else {
                dfs(nums, target - num);
            }
        }
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp;

        dp.push_back(1);

        for (int i = 1; i <= target; i++) {
            unsigned long long val;

            val = 0;

            for (int& num: nums) {
                if (i - num >= 0) {
                    val += dp[i - num];
                }
            }

            dp.push_back(val);
        }

        return dp[target];
    }
};