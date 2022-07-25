#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLeftPosition(vector<int> &nums, int target, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }
        if (l == r && nums[l] == target)
        {
            return l;
        }

        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            return findLeftPosition(nums, target, l, mid);
        }
        else if (nums[mid] < target)
        {
            return findLeftPosition(nums, target, mid + 1, r);
        }
        else
        {
            return findLeftPosition(nums, target, l, mid - 1);
        }
    }

    int findRightPosition(vector<int> &nums, int target, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }
        if (l == r && nums[l] == target)
        {
            return l;
        }
        if (l == r - 1)
        {
            if (nums[r] == target)
            {
                return r;
            }
            if (nums[l] == target)
            {
                return l;
            }
        }

        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            return findRightPosition(nums, target, mid, r);
        }
        else if (nums[mid] < target)
        {
            return findRightPosition(nums, target, mid + 1, r);
        }
        else
        {
            return findRightPosition(nums, target, l, mid - 1);
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> rst = {
            findLeftPosition(nums, target, 0, nums.size() - 1),
            findRightPosition(nums, target, 0, nums.size() - 1)};

        return rst;
    }
};
