/**
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool binarySearch(vector<vector<int>> &matrix, int x1, int x2, int y1, int y2, int target)
    {
        if (x1 > x2 || y1 > y2)
        {
            return false;
        }
        if (x1 == x2 && y1 == y2)
        {
            if (matrix[x1][y1] == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int mid_x = (x1 + x2) / 2;
        int mid_y = (y1 + y2) / 2;

        if (matrix[mid_x][mid_y] == target)
        {
            return true;
        }
        else
        {
            bool rest_two = binarySearch(matrix, x1, mid_x, mid_y + 1, y2, target) || binarySearch(matrix, mid_x + 1, x2, y1, mid_y, target);

            if (matrix[mid_x][mid_y] < target)
            {
                return rest_two || binarySearch(matrix, mid_x + 1, x2, mid_y + 1, y2, target);
            }
            else
            {
                return rest_two || binarySearch(matrix, x1, mid_x, y1, mid_y, target);
            }
        }
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return binarySearch(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};
*/
