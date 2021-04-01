#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


#define MAX_N 20
#define MAX_M 4
#define MAX_WEIGHT 100
#define WEIGHT_SUM (MAX_WEIGHT * MAX_N)


int weight[MAX_N], ans, n, m;
bool discard[MAX_N];


void cal_weight_sum() {
    bool weight_sum[WEIGHT_SUM + 1];
    memset(weight_sum, false, sizeof(weight_sum));
    weight_sum[0] = true;
    
    int tot = 0;
    int tmp = 0;
    
    for (int i = 0; i < n; i++) {
        if (discard[i])
            continue;
        
        for (int j = tot; j >= 0; j--) {
            if (weight_sum[j] && !weight_sum[j + weight[i]]) {
                weight_sum[j + weight[i]] = true;
                tmp++;
            }
        }

        tot += weight[i];
    }

    ans = max(ans, tmp);
}


void dfs(int w, int dis) {
    if (dis > m)
        return;
    if (w == n) {
        if (dis == m)
            cal_weight_sum();
        return;
    }
    dfs(w + 1, dis);
    discard[w] = true;
    dfs(w + 1, dis + 1);
    discard[w] = false;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}