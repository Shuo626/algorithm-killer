#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> matrix_prefix_sum(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    matrix_prefix_sum[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    matrix_prefix_sum[i][j] = matrix_prefix_sum[i][j - 1] + matrix[i][j];
                }
                else if (j == 0)
                {
                    matrix_prefix_sum[i][j] = matrix_prefix_sum[i - 1][j] + matrix[i][j];
                }
                else
                {
                    matrix_prefix_sum[i][j] = matrix_prefix_sum[i - 1][j] + matrix_prefix_sum[i][j - 1] - matrix_prefix_sum[i - 1][j - 1] + matrix[i][j];
                }
            }
        }

        int rst = 0;

        for (int x1 = 0; x1 < m; x1++)
        {
            for (int x2 = x1; x2 < m; x2++)
            {
                map<int, int> num_sub_matrix;
                num_sub_matrix[0] = 1;

                for (int y = 0; y < n; y++)
                {
                    int sub_matrix_sum;

                    if (x1 == 0)
                    {
                        sub_matrix_sum = matrix_prefix_sum[x2][y];
                    }
                    else
                    {
                        sub_matrix_sum = matrix_prefix_sum[x2][y] - matrix_prefix_sum[x1 - 1][y];
                    }

                    if (num_sub_matrix.find(sub_matrix_sum - target) != num_sub_matrix.end())
                    {
                        rst += num_sub_matrix[sub_matrix_sum - target];
                    }

                    num_sub_matrix[sub_matrix_sum] += 1;
                }
            }
        }

        return rst;
    }
};
