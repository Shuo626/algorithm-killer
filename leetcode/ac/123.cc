#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int dp[100000][4];

    enum Stage {
        Buy1 = 0,
        Sell1,
        Buy2,
        Sell2
    };


    int maxProfit(vector<int>& prices) {
        dp[0][Buy1] = -prices[0];
        dp[0][Sell1] = 0;
        dp[0][Buy2] = -prices[0];
        dp[0][Sell2] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][Buy1] = max(dp[i - 1][Buy1], -prices[i]);
            dp[i][Sell1] = max(dp[i - 1][Sell1], dp[i - 1][Buy1] + prices[i]);
            dp[i][Buy2] = max3(dp[i - 1][Buy2], dp[i - 1][Sell1] - prices[i], dp[i][Sell1] - prices[i]);
            dp[i][Sell2] = max3(dp[i - 1][Sell2], dp[i - 1][Buy2] + prices[i], dp[i][Buy2] + prices[i]);
        }

        return dp[prices.size() - 1][Sell2];
    }

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
};