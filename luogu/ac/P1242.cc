#include <bits/stdc++.h>

using namespace std;


#define MAX_DISK 50
#define MAX_CYLINDER 3
#define INF 0x3f3f3f3f


char ori[MAX_DISK], des[MAX_DISK], tmp1_ori[MAX_DISK][MAX_DISK], tmp2_ori[MAX_DISK][MAX_DISK];
int disk_num;
int ans;

struct Step {
    char from;
    char to;
    int d;
};

vector<Step> steps, tmp1_steps[MAX_DISK], tmp2_steps[MAX_DISK];


Step get_step(int d, char from, char to) {
    Step s;
    s.d = d;
    s.from = from;
    s.to = to;

    return s;
}


void basic_dfs(int disk, char from, char to, bool mv) {
    if (disk == 1) {
        if (from != to) {
            cout << "move " << disk << " from " << from << " to " << to << endl;
            ori[disk] = to;
            ans++;
        }
        return;
    }
    if (from == to) {
        basic_dfs(disk - 1, ori[disk - 1], mv? des[disk - 1]: to, mv);
        return;
    }
    char another = 'A';
    while (another == from || another == to)
        another++;
    basic_dfs(disk - 1, ori[disk - 1], another, false);
    cout << "move " << disk << " from " << from << " to " << to << endl;
    ans++;
    ori[disk] = to;
    basic_dfs(disk - 1, another, mv? des[disk - 1]: to, mv);
}


int dfs(int disk, char from, char to, bool mv) {
    if (disk == 1) {
        if (from == to)
            return 0;
        steps.push_back(get_step(disk, from, to));
        ori[disk] = to;
        return 1;
    }
    if (from != to) {
        int step1, step2;
        step1 = step2 = 0;

        copy(ori + 1, ori + disk_num + 1, tmp1_ori[disk] + 1);
        tmp1_steps[disk].clear();
        tmp1_steps[disk].resize(steps.size());
        copy(steps.begin(), steps.end(), tmp1_steps[disk].begin());

        // mv func 1
        {
            char another = 'A';
            while (another == from || another == to)
                another++;
            
            step1 += dfs(disk - 1, ori[disk - 1], another, false);

            steps.push_back(get_step(disk, from, to));
            step1++;
            ori[disk] = to;

            step1 += dfs(disk - 1, ori[disk - 1], mv? des[disk - 1]: to, mv);
        }

        copy(ori + 1, ori + 1 + disk_num, tmp2_ori[disk] + 1);
        copy(tmp1_ori[disk] + 1, tmp1_ori[disk] + disk_num + 1, ori + 1);
        tmp2_steps[disk].resize(steps.size());
        copy(steps.begin(), steps.end(), tmp2_steps[disk].begin());
        steps.resize(tmp1_steps[disk].size());
        copy(tmp1_steps[disk].begin(), tmp1_steps[disk].end(), steps.begin());

        // mv func 2
        {
            char another = 'A';
            while (another == from || another == to)
                another++;

            step2 += dfs(disk - 1, ori[disk - 1], to, false);
            
            step2++;
            steps.push_back(get_step(disk, from, another));
            ori[disk] = another;

            step2 += dfs(disk - 1, to, from, false);
            
            step2++;
            steps.push_back(get_step(disk, another, to));
            ori[disk] = to;

            step2 += dfs(disk - 1, from, mv? des[disk - 1]: to, mv);
        }

        if (step1 < step2) {
            copy(tmp2_ori[disk] + 1, tmp2_ori[disk] + disk_num + 1, ori + 1);
            steps.clear();
            steps.resize(tmp2_steps[disk].size());
            copy(tmp2_steps[disk].begin(), tmp2_steps[disk].end(), steps.begin());
        }

        return min(step1, step2);
    } else {

        return dfs(disk - 1, ori[disk - 1], mv? des[disk - 1]: to, mv);
    }
    return 0;
}


int main() {
    cin >> disk_num;

    for (int i = 0; i < MAX_CYLINDER; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            ori[d] = i + 'A';
        }
    }

    for (int i = 0; i < MAX_CYLINDER; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            des[d] = i + 'A';
        }
    }

    if (disk_num < 14) {
        int _ans = dfs(disk_num, ori[disk_num], des[disk_num], true);
    for (Step s: steps) {
        cout << "move " << s.d << " from " << s.from << " to " << s.to << endl;
    }
    cout << _ans << endl;
    } else {
        basic_dfs(disk_num, ori[disk_num], des[disk_num], true);
        cout << ans << endl;
    }
}