#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left > right)
            return;
        
        int mid;
        
        mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot, i, j, tmp;

        pivot = nums[right];
        i = left;
        j = left;

        while (j < right) {
            if (nums[j] < pivot) {
                tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                i++;
            }
            j++;
        }

        nums[right] = nums[i];
        nums[i] = pivot;

        return i;
    }
};