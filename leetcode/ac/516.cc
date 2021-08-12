#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
        }

        for (int len = 3; len <= s.size(); len++) {
            for (int i = 0; i < s.size() - len + 1; i++) {
                int j;

                j = i + len - 1;

                if (s[i] != s[j]) {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }

                // cout << "i: " << i << " j: " << j << " dp[i][j]: " << dp[i][j] << endl;
            }
        }

        return dp[0][s.size() - 1];
    }
};