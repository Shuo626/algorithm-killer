#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dpWithFirst, dpWithoutFirst;
        dpWithFirst.push_back(nums[0]);
        dpWithoutFirst.push_back(0);

        if (nums.size() >= 2) {
            dpWithFirst.push_back(nums[0]);
            dpWithoutFirst.push_back(nums[1]);
        }

        for (int i = 2; i < nums.size(); i++) {
            if (i < nums.size() - 1) {
                dpWithFirst.push_back(max(nums[i] + dpWithFirst[i - 2], dpWithFirst[i - 1]));
            } else {
                dpWithFirst.push_back(dpWithFirst[i - 1]);
            }
            dpWithoutFirst.push_back(max(nums[i] + dpWithoutFirst[i - 2], dpWithoutFirst[i - 1]));
        }

        return max(dpWithFirst[nums.size() - 1], dpWithoutFirst[nums.size() - 1]);
    }
};