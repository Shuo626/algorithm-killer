#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    map<int, int> rabitts;

    int numRabbits(vector<int>& answers) {
        int ans;

        ans = 0;
        
        for (auto& n: answers) {
            rabitts[n] += 1;
        }

        for (auto& kv: rabitts) {
            ans += roundUp(kv.second, kv.first + 1) * (kv.first + 1);
        }

        return ans;
    }


    int roundUp(int a, int b) {
        return (a + b - 1) / b;
    }
};