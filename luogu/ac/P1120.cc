#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


const int INF = 0x3f3f3f3f;
int sticks[51], tot, max_l, min_l;


void dfs(int tar_len, int len, int l, int res) {
    if (res == 0) {
        cout << tar_len << endl;
        exit(0);
    }
    if (len == tar_len) {
        dfs(tar_len, 0, max_l, res - 1);
        return;
    }
    for (int i = l; i >= min_l; i--) {
        if (sticks[i] > 0 && i + len <= tar_len) {
            sticks[i]--;
            dfs(tar_len, len + i, i, res);
            sticks[i]++;
            if (len == 0 || len + i == tar_len)
                break;
        }
    }
}


int main() {
    int N;
    cin >> N;
    max_l = -INF;
    min_l = INF;
    
    while (N--) {
        int stick;
        cin >> stick;
        if (stick <= 50) {
            sticks[stick]++;
            tot += stick;
            max_l = max_l < stick ? stick : max_l;
            min_l = min_l > stick ? stick : min_l;
        }
    }

    for (int i = max_l; i <= tot; i++) {
        if (tot % i == 0) {
            dfs(i, 0, max_l, tot / i);
        }
    }

    cout << tot << endl;
}