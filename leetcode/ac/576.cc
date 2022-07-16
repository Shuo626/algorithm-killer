#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dp[51][51][51];
    long long mod = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }

    int dfs(int m, int n, int step, int i, int j)
    {
        if (i < 0 || i == m || j < 0 || j == n)
        {
            return 1;
        }

        if (step <= 0)
        {
            return 0;
        }

        if (dp[i][j][step] != -1)
        {
            return dp[i][j][step];
        }

        auto up = dfs(m, n, step - 1, i - 1, j) % mod;
        auto down = dfs(m, n, step - 1, i + 1, j) % mod;
        auto left = dfs(m, n, step - 1, i, j - 1) % mod;
        auto right = dfs(m, n, step - 1, i, j + 1) % mod;

        int rst = (up + down + left + right) % mod;
        dp[i][j][step] = rst;

        return rst;
    }
};

int main()
{
    Solution sol;

    int ans = sol.findPaths(2, 2, 2, 0, 0);
}
