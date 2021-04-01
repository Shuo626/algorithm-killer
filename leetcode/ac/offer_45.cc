#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    string minNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return cat(nums);
    }

    string cat(vector<int>& nums) {
        string number;

        for (int n: nums) {
            number += to_string(n);
        }

        return number;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l > r)
            return;
        
        int mid;
        mid = partition(nums, l, r);
        quickSort(nums, l, mid - 1);
        quickSort(nums, mid + 1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivot, i, j, tmp;

        pivot = nums[r];
        i = l;
        j = l;

        while (j < r) {
            if (compare(nums[j], pivot) < 0) {
                tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                i++;
            }
            j++;
        }

        nums[r] = nums[i];
        nums[i] = pivot;

        return i;
    }

    int compare(int num1, int num2) {
        string tmp_num1, tmp_num2;
        
        tmp_num1 = to_string(num1) + to_string(num2);
        tmp_num2 = to_string(num2) + to_string(num1);

        if (tmp_num1 < tmp_num2) {
            return -1;
        } else if (tmp_num1 == tmp_num2) {
            return 0;
        } else {
            return 1;
        }
    }
};
