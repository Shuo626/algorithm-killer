#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l, r;
        l = 0;
        r = nums.size() - 1;

        k -= 1;
        while (true) {
            int mid;
            mid = sort(nums, l, r);

            if (mid == k) {
                return nums[mid];
            } else if (mid < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    int sort(vector<int>& nums, int l, int r) {
        int i, j;
        i = l;
        j = l;

        int tmp;
        tmp = nums[r];

        while (j < r) {
            if (nums[j] > tmp) {
                swap(nums, i, j);
                i++;
            }

            j++;
        }

        nums[r] = nums[i];
        nums[i] = tmp;

        return i;
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp;
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};