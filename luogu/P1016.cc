#include <cstdio>
#include <iostream>

using namespace std;


// max num of station and one start and one end
const int MAX_N = 6 + 2;
const int INF = 0x3f3f3f3f;


int main() {
    int N;
    float min_cost;
    float D1, C, D2, P;
    float rest_C, need_C;
    float Di[MAX_N], Pi[MAX_N];

    

    cin >> D1 >> C >> D2 >> P >> N;

    Di[0] = 0;
    Pi[0] = P;

    float last_D;
    
    for (int i = 1; i < N + 1; i++) {
        float d, p;
        cin >> d >> p;
        Di[i] = d - Di[i - 1];
        Pi[i] = p;
        if (i == N)
            last_D = d;
    }
    
    Di[N + 1] = D1 - last_D;
    Pi[N + 1] = INF;

    rest_C = 0;

    for (int i = 0; i < N; i++) {
        if (C * D2 < Di[i + 1]) {
            cout << "No Solution" << endl;
            return 1;
        } else {
            rest_C -= Di[i] / D2;
            if (Pi[i] <= Pi[i + 1]) {
                rest_C = C;
                min_cost += Pi[i] * (C - rest_C);
            } else {
                need_C = Di[i + 1] / D2;
                rest_C = need_C;
                min_cost += Pi[i] * (need_C - rest_C);
            }
        }
    }

    need_C = Di[N + 1] / D2;
    min_cost += Pi[N] * (need_C - rest_C);

    cout << min_cost << endl;

}