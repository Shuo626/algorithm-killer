#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int l, r;

        r = 0;
        l = 0;
        for (int t: time) {
            r += t;
        }

        while (l < r) {
            int t;
            t = (l + r) / 2;

            if (check(time, m, t)) {
                r = t;
            } else {
                l = t + 1;
            }
        }

        return l;
    }

    bool check(vector<int>& time, int m, int T) {
        int rest, day, maxT;
        bool flag;

        rest = T;
        day = 1;
        maxT = -1;
        flag = true;

        for (int i = 0; i < time.size(); i++) {
            int t;
            t = time[i];

            maxT = max(maxT, t);

            if (rest >= t) {
                rest -= t;
            } else if (flag && rest + maxT >= t) {
                rest = rest + maxT - t;
                flag = false;
            } else {
                day++;
                maxT = -1;
                rest = T;
                i--;
                flag = true;
            }
        }

        if (day > m)
            return false;
        else
            return true;
    }
};