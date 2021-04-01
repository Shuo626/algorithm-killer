#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> dp;

    int longestValidParentheses(string s) {
        dp.push_back(0);

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(') {
                dp.push_back(0);
            } else {
                if (s[i - 1] == '(') {
                    dp.push_back(getDp(i - 2) + 2);
                } else {
                    int prev;
                    prev = i - 1 - getDp(i - 1);
                    
                    if (prev >= 0 && s[prev] == '(') {
                        dp.push_back(getDp(i - 1) + getDp(i - 1 - getDp(i - 1) - 1) + 2);
                    } else {
                        dp.push_back(0);
                    }
                }
            }
        }

        return getMaxVector();
    }

    int getDp(int idx) {
        if (idx < 0) {
            return 0;
        } else {
            return dp[idx];
        }
    }

    int getMaxVector() {
        int result;
        result = 0;

        for (int& x: dp) {
            result = max(result, x);
        }

        return result;
    }
};