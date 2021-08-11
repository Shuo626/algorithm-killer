#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n;

        n = nums.size();

        vector<map<long long, int>> dp(n);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d;

                d = 1LL * nums[i] - nums[j];

                if (dp[i].find(d) == dp[i].end()) {
                    dp[i][d] = 0;
                }

                auto it = dp[j].find(d);

                dp[i][d] += it == dp[j].end()? 0: it->second;
                dp[i][d] += 1;
            }
        }

        int ans;

        ans = 0;

        for (auto& slice: dp) {
            for (auto& it: slice) {
                ans += it.second;
            }
        }

        return ans - n * (n - 1) / 2; 
    }
};