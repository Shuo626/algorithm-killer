#include <bits/stdc++.h>

using namespace std;


#define INF 0x3f3f3f3f
#define MAX_N 1005


vector<int> tree[MAX_N];
int dp[MAX_N][5];

enum CoverLevel {
    COVER_GRANDPARENT = 0,
    COVER_PARENT,
    COVER_SELF,
    COVER_CHILD,
    COVER_GRANDSON
};


int sum_child_state(int node, int state) {
    int ans = 0;
    for (int child: tree[node]) {
        ans += dp[child][state];
    }

    return ans;
}


int min_child_cover_state(int node, int s1, int s2) {
    int ans = INF;
    for (int c1: tree[node]) {
        int sum = 0;
        sum += dp[c1][s1];
        for (int c2: tree[node]) {
            if (c1 == c2)
                continue;

            sum += dp[c2][s2];
        }
        ans = min(ans, sum);
    }
    return ans;
}


int get_min_cover_grandparent(int node) {
    return 1 + sum_child_state(node, COVER_GRANDSON);
}


int get_min_cover_parent(int node) {
    return min(min_child_cover_state(node, COVER_GRANDPARENT, COVER_CHILD), dp[node][COVER_GRANDPARENT]);
}


int get_min_cover_self(int node) {
    return min(min(dp[node][COVER_GRANDPARENT], dp[node][COVER_PARENT]), 
               min_child_cover_state(node, COVER_PARENT, COVER_SELF));
}


int get_min_cover_child(int node) {
    int sum = 0;
    for (int child: tree[node]) {
        sum += dp[child][COVER_SELF];
    }
    return min(sum, min(min(dp[node][COVER_GRANDPARENT], dp[node][COVER_PARENT]), dp[node][COVER_SELF]));
}

int get_min_cover_grandson(int node) {
    int sum = 0;
    for (int child: tree[node]) {
        sum += dp[child][COVER_CHILD];
    }
    return min(sum, min(min(dp[node][COVER_GRANDPARENT], dp[node][COVER_PARENT]), min(dp[node][COVER_SELF], dp[node][COVER_CHILD])));
}


void dfs(int node) {
    for (int child: tree[node]) {
        dfs(child);
    }
    dp[node][COVER_GRANDPARENT] = get_min_cover_grandparent(node);
    dp[node][COVER_PARENT] = get_min_cover_parent(node);
    dp[node][COVER_SELF] =  get_min_cover_self(node);
    dp[node][COVER_CHILD] = get_min_cover_child(node);
    dp[node][COVER_GRANDSON] = get_min_cover_grandson(node);
}


int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int ai;
        cin >> ai;
        tree[ai].push_back(i);
    }

    dfs(1);

    cout << dp[1][COVER_SELF] << endl;
}