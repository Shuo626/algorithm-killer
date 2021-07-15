#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int INF = 0x3f3f3f3f;
        int dp[101][21][101];

        memset(dp, INF, sizeof(dp));

        if (houses[0] != 0) {
            dp[1][houses[0]][1] = 0;
        } else {
            for (int i = 1; i <= n; i++) {
                dp[1][i][1] = cost[0][i - 1];
            }
        }

        for (int i = 2; i <= m; i++) {
            if (houses[i - 1] != 0) {
                for (int k = 1; k <= target; k++) {
                    if (k > i) {
                        break;
                    }

                    int val = INF;

                    for (int p = 1; p <= n; p++) {
                        if (p != houses[i - 1]) {
                            val = min(val, dp[i - 1][p][k - 1]);
                        } else {
                            val = min(val, dp[i - 1][p][k]);
                        }
                    }

                    dp[i][houses[i - 1]][k] = val;
                }
            } else {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= target; k++) {
                        if (k > i) {
                            break;
                        }

                        int val = INF;

                        for (int p = 1; p <= n; p++) {
                            if (p != j) {
                                val = min(val, dp[i - 1][p][k - 1] + cost[i - 1][j - 1]);
                            } else {
                                val = min(val, dp[i - 1][p][k] + cost[i - 1][j - 1]);
                            }
                        }

                        dp[i][j][k] = val;
                    }
                }
            }
        }

        int ans = INF;

        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m][i][target]);
        }

        if (ans == INF) {
            return -1;
        } else {
            return ans;
        }
    }
};


int main() {
    Solution solution;

    vector<int> houses = {0, 0, 0, 0, 0};
    vector<vector<int>> cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};

    solution.minCost(houses, cost, 5, 2, 3);

}