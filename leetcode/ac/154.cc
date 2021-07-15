#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        return _findMin(nums, 0, nums.size() - 1);
    }


    int _findMin(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        
        int mid;

        mid = (left + right) / 2;

        if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }

        if (nums[mid] > nums[right]) {
            return _findMin(nums, mid + 1, right);
        } else if (nums[mid] < nums[right]) {
            return _findMin(nums, left, mid - 1);
        } else {
            return _findMin(nums, left, right - 1);
        }
    }
};