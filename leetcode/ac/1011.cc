#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int maxWeight, sum;
        maxWeight = 0;
        sum = 0;

        for (int& w: weights) {
            maxWeight = max(maxWeight, w);
            sum += w;
        }

        int ans;

        ans = binarySearch(maxWeight, sum, D, weights);

        return ans;
    }


    int binarySearch(int left, int right, int D, vector<int>& weights) {
        if (right - left == 1) {
            if (check(left, D, weights)) {
                return left;
            } else {
                return right;
            }
        }

        int mid;

        mid = (left + right) / 2;

        if (check(mid, D, weights)) {
            return binarySearch(left, mid, D, weights);
        } else {
            return binarySearch(mid, right, D, weights);
        }
    }


    bool check(int capacity, int D, vector<int>& weights) {
        int day, tmp;

        day = 1;
        tmp = 0;

        for (int& w: weights) {
            tmp += w;

            if (tmp > capacity) {
                tmp = w;
                day += 1;

                if (day > D) {
                    return false;
                }
            }
        }

        return true;
    }
};