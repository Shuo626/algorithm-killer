#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> positionNum;
        int maxPosition;
        maxPosition = 0;

        for (vector<int>& row: wall) {
            if (row.size() == 1) {
                continue;
            }

            int position;
            position = 0;

            for (int i = 0; i < row.size() - 1; i++) {
                position += row[i];
                positionNum[position] += 1;

                maxPosition = max(maxPosition, positionNum[position]);
            }
        }

        return wall.size() - maxPosition;
    }
};