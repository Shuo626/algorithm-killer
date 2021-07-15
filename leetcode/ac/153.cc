#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int firstElement;


    int findMin(vector<int>& nums) {
        firstElement = nums[0];

        if (nums.back() < firstElement) {
            return nums[binarySearch(0, nums.size() - 1, nums)];    
        } else {
            return nums[0];
        }    
    }


    int binarySearch(int start, int end, vector<int> &nums) {
        int mid;

        mid = (start + end) / 2;

        if (mid == 0) {
            return mid + 1;
        }

        if (nums[mid] < nums[mid - 1]) {
            return mid;
        }

        if (nums[mid] > firstElement) {
            return binarySearch(mid + 1, end, nums);
        } else {
            return binarySearch(start, mid - 1, nums);
        }
    }
};