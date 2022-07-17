#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {0};
        const int mod = 1e9 + 7;

        dp[1][0] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                long long tmp = 0;
                for (int h = 0; h < i; h++)
                {
                    if (j - h >= 0)
                    {
                        tmp = (tmp + dp[i - 1][j - h]) % mod;
                    }
                }

                dp[i][j] = tmp;
            }
        }

        return dp[n][k];
    }
};
