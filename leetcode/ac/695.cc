#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<int>> flag(grid.size(), vector<int>(grid[0].size(), 0));

        int rst = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 && flag[i][j] != 1)
                {
                    rst = max(rst, areaOfIsland(grid, flag, i, j));
                }
            }
        }

        return rst;
    }

    int areaOfIsland(vector<vector<int>> &grid, vector<vector<int>> &flag, int i, int j)
    {
        if (flag[i][j] == 1 || grid[i][j] == 0)
        {
            return 0;
        }

        flag[i][j] = 1;
        int area = 1;

        // right
        if (j + 1 < grid[0].size())
        {
            area += areaOfIsland(grid, flag, i, j + 1);
        }
        // left
        if (j - 1 >= 0)
        {
            area += areaOfIsland(grid, flag, i, j - 1);
        }
        // up
        if (i - 1 >= 0)
        {
            area += areaOfIsland(grid, flag, i - 1, j);
        }
        // down
        if (i + 1 < grid.size())
        {
            area += areaOfIsland(grid, flag, i + 1, j);
        }

        return area;
    }
};
