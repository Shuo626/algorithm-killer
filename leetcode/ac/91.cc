#include <bits/stdc++.h>


using namespace std;


class Solution0 {
public:
    int len, ans;
    string num;

    int numDecodings(string s) {
        len = s.size();
        ans = 0;
        num = s;

        dfs(0);

        return ans;
    }


    void dfs(int index) {
        if (index == len) {
            ans += 1;
            return;
        }

        if (num[index] == '0') {
            return;
        }

        dfs(index + 1);
        if (index + 1 < len && check(num.substr(index, 2))) {
            dfs(index + 2);
        }
    }


    bool check(string s) {
        if (s <= "26") {
            return true;
        } else {
            return false;
        }
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp;

        dp.push_back(1);
        dp.push_back(1);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '0' || s[i - 1] > '2') {
                    return 0;
                }
                dp.push_back(dp[i + 1 - 2]);
            } else if (check(s.substr(i - 1, 2))) {
                dp.push_back(dp[i + 1 - 1] + dp[i + 1 -2]);
            } else {
                dp.push_back(dp[i + 1 - 1]);
            }
        }

        return dp[s.size()];
    }


    bool check(string s) {
        if (s >= "11" && s <= "26") {
            return true;
        } else {
            return false;
        }
    }
};