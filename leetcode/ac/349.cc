#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    map<int, bool> setMap;
    map<int, bool> ansMap;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int n: nums1) {
            if (setMap.count(n) == 0) {
                setMap[n] = true;
            }
        }
        for (int n: nums2) {
            if (setMap.count(n) == 1 && ansMap.count(n) == 0) {
                ansMap[n] = true;
                ans.push_back(n);
            }
        }

        return ans;
    }
};