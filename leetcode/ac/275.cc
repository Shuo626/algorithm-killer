#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        return binarySearch(citations.size() - 1, 0, citations.size() - 1, citations);
    }


    int binarySearch(int len, int l, int r, vector<int>& citations) {
        if (l > r) {
            return len -l + 1;
        }

        int mid;
        mid = (l + r) / 2;

        if (citations[mid] == len - mid + 1) {
            return len - mid + 1;
        } else if (citations[mid] < len - mid + 1) {
            return binarySearch(len, mid + 1, r, citations);
        } else {
            return binarySearch(len, l, mid - 1, citations);
        }
    }
};