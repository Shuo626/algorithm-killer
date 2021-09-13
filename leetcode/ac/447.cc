#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans;

        ans = 0;

        map<int, int> disToNum;

        for (int i = 0; i < points.size(); i++) {
            disToNum.clear();

            for (int j = 0; j < points.size(); j++) {
                int d;

                d = distance(points[i][0], points[i][1], points[j][0], points[j][1]);

                if (disToNum.find(d) == disToNum.end()) {
                    disToNum[d] = 0;
                }

                disToNum[d] = disToNum[d] + 1;
            }

            for (auto it = disToNum.begin(); it != disToNum.end(); it++) {
                if (it->second >= 2) {
                    ans += Cn2(it->second) * 2;
                }
            }
        }

        return ans;
    }


    int distance(int x1, int y1, int x2, int y2) {
        return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
    }


    int Cn2(int n) {
        return n * (n - 1) / 2;
    }
};


int main() {
    Solution solution;

    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};

    solution.numberOfBoomerangs(points);
}