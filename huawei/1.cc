#include <bits/stdc++.h>


using namespace std;


int min3(int a, int b, int c) {
    return min(a, min(b, c));
}


int main() {
    int m, n;
    int mat[100][100], dp[100][100];

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    dp[0][0] = mat[0][0];

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + mat[0][j];
        if (mat[0][j] == mat[0][j - 1]) {
            dp[0][j] -= 1;
        }
    }

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + mat[i][0];
        if (mat[i][0] == mat[i - 1][0]) {
            dp[i][0] -= 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int a, b, c;
            a = dp[i - 1][j];
            b = dp[i - 1][j - 1];
            c = dp[i][j - 1];

            if (mat[i][j] == mat[i - 1][j]) {
                a -= 1;
            }
            if (mat[i][j] == mat[i - 1][j - 1]) {
                b -= 1;
            }
            if (mat[i][j] == mat[i][j - 1]) {
                c -= 1;
            }

            dp[i][j] = min3(a, b, c) + mat[i][j];
        }
    }

    cout << dp[m - 1][n - 1];
}