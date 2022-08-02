#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;

        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
