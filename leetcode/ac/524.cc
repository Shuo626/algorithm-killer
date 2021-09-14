#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for (auto& subs: dictionary) {
            if (isSubString(subs, s)) {
                if (subs.size() > ans.size()) {
                    ans = subs;
                } else if (subs.size() == ans.size() && subs < ans) {
                    ans = subs;
                }
            }
        }

        return ans;
    }


    bool isSubString(string& subs, string& s) {
        int p1, p2;

        p1 = p2 = 0;

        while (p1 < s.size() && p2 < subs.size()) {
            if (s[p1] == subs[p2]) {
                p1++;
                p2++;
            } else {
                p1++;
            }
        }

        return p2 == subs.size();
    }
};
