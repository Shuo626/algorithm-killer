#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> nums;
    int sum;

    NumArray(vector<int> &nums) : nums(nums), sum(0)
    {
        for (auto n : nums)
        {
            sum += n;
        }
    }

    void update(int index, int val)
    {
        sum = sum - nums[index] + val;
        nums[index] = val;
    }

    int calSum(int l, int r)
    {
        int rst = 0;
        for (int i = l; i <= r; i++)
        {
            rst += nums[i];
        }

        return rst;
    }

    int sumRange(int left, int right)
    {
        if (right - left < nums.size() / 2)
        {
            return calSum(left, right);
        }
        else
        {
            return sum - calSum(0, left - 1) - calSum(right + 1, nums.size() - 1);
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    auto *obj = new NumArray(nums);
    obj->update(0, 233);
    cout << obj->sumRange(0, 1);
}
