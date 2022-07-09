#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp;
        priority_queue<pair<int, int>> pq;
        dp.push_back(nums[0]);
        pq.push({dp[0], 0});

        for (int i = 1; i < nums.size(); i++)
        {
            while (pq.top().second < i - k)
            {
                pq.pop();
            }

            dp.push_back(pq.top().first + nums[i]);
            pq.push({dp[i], i});
        }

        return dp[nums.size() - 1];
    }
};
