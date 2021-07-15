#include <bits/stdc++.h>


using namespace std;


int dp[35][35];


bool canRun(int x, int y, int x1, int y1) {
    if (x == x1 - 2 && y == y1 - 1) {
        return false;
    }
    if (x == x1 - 1 && y == y1 - 2) {
        return false;
    }
    if (x == x1 - 2 && y == y1 + 1) {
        return false;
    }
    if (x == x1 - 1 && y == y1 + 2) {
        return false;
    }
    if (x == x1 + 1 && y == y1 - 2) {
        return false;
    }
    if (x == x1 + 2 && y == y1 - 1) {
        return false;
    }
    if (x == x1 + 1 && y == y1 + 2) {
        return false;
    }
    if (x == x1 + 2 && y == y1 + 1) {
        return false;
    }

    if (x == x1 + 1 && y == y1 + 1) {
        return false;
    }

    return true;
}


int getVal(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    } else {
        return dp[i][j];
    }
}


int main() {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    dp[0][0] = 1;

    for (int i = 1; i <= y2; i++) {
        for (int j = 1; j <= x2; j++) {
            if (!canRun(j, i, x1, y1)) {
                continue;
            }

            dp[i][j] = getVal(i - 1, j - 2) + getVal(i - 2, j - 1);
        }
    }

    cout << dp[y2 - 1][x2 - 2] + dp[y2 - 2][x2 - 1] << endl;;
}