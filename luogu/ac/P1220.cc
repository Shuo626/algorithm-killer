#include <bits/stdc++.h>

using namespace std;


#define INF 0x3f3f3f3f
#define MAX_N 55


int n, c, posi[MAX_N], sum[MAX_N], dp[MAX_N][MAX_N][2];


int main() {
    memset(dp, INF, sizeof(dp));
    
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        int p, w;
        cin >> p >> w;
        posi[i] = p;
        sum[i] = sum[i - 1] + w;
    }

    dp[c][c][0] = dp[c][c][1] = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (posi[i + 1] - posi[i]) * (sum[i] + sum[n] - sum[j]),
                              dp[i + 1][j][1] + (posi[j] - posi[i]) * (sum[i] + sum[n] - sum[j]));
            dp[i][j][1] = min(dp[i][j - 1][1] + (posi[j] - posi[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]),
                              dp[i][j - 1][0] + (posi[j] - posi[i]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    }

    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
}