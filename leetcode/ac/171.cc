#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int base, ans;

        base = 26;
        ans = 0;

        for (int i = 1; i <= columnTitle.size(); i++) {
            ans += pow(base, columnTitle.size() - i) * (columnTitle[i - 1] - 'A' + 1);
        }

        return ans;
    }
};