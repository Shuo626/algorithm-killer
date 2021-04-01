#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> dp;


    int maxProfit(vector<int>& prices) {
        dp.push_back(0);

        for (int i = 1; i < prices.size(); i++) {
            if (dp[i - 1] < 0 && (prices[i] - prices[i - 1]) > 0) {
                dp.push_back(prices[i] - prices[i - 1]);
            } else {
                dp.push_back(prices[i] - prices[i - 1] + dp[i - 1]);
            }
        }

        return getMax();
    }

    int getMax() {
        int result;
        result = 0;

        for (int& x: dp) {
            result = max(result, x);
        }

        return result;
    }
};