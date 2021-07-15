#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;

        int i, j;
        i = 0;
        j = 0;

        while (i < m && j < n) {
            while (i < m && j < n && nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            }

            while (i < m && j < n && nums2[j] < nums1[i]) {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        nums1 = result;
    }
};

