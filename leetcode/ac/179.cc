#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> _nums;

        for (int& num: nums) {
            _nums.push_back(to_string(num));
        }

        sort(_nums.begin(), _nums.end(), _compare);

        string ans;

        ans = "";

        for (string& num: _nums) {
            ans += num;
        }

        if (ans[0] == '0') {
            return "0";
        } else {
            return ans;
        }
    }


    static bool _compare(string& a, string& b) {
        string ab, ba;
        ab = a + b;
        ba = b + a;

        return ab > ba;
    }
};