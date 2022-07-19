#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> rst;

        rst.push_back(vector<int>(1, 1));

        for (int i = 1; i < numRows; i++)
        {
            rst.push_back(vector<int>(i + 1));
            rst[i][0] = 1;
            rst[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                rst[i][j] = rst[i - 1][j - 1] + rst[i - 1][j];
            }
        }

        return rst;
    }
};
