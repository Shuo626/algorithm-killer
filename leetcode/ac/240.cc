#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col;
        row = 0;
        col = matrix[0].size() - 1;

        while (true) {
            if (row >= matrix.size() || col < 0) {
                return false;
            }
            
            int tmp;
            tmp = matrix[row][col];
            if (target == tmp) {
                return true;
            } else if (target > tmp) {
                row += 1;
                col = col;
            } else if (target < tmp) {
                row = row;
                col -= 1;
            }
        }
    }


};