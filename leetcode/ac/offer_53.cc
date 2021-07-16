#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int position, ans;
        ans = 0;

        position = binarySearch(nums, target, 0, nums.size() - 1);

        while (position < nums.size() && nums[position] == target) {
            ans++;
            position++;
        }

        return ans;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return left;
        }

        int mid;
        mid = (left + right) / 2;

        if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, right);
        } else {
            return binarySearch(nums, target, left, mid - 1);
        }
    }
};