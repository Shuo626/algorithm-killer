#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> matPreSum(100, vector<int>(100, 0));

        initMatPreSum(matPreSum, matrix);

        int rows, columns;

        rows = matrix.size();
        columns = matrix[0].size();

        int ans;

        ans = -INT_MAX;

        // m: top, n: left, p: bottom, q: right
        for (int m = 0; m < rows; m++) {
            for (int p = m; p < rows; p++) {
                set<int> subRectangles;
                subRectangles.insert(0);

                for (int q = 0; q < columns; q++) {
                    int subRecVal;
                    subRecVal = getSubRecVal(matPreSum, m, 0, p, q);

                    if (subRectangles.find(subRecVal - k) != subRectangles.end()) {
                        return k;
                    } else if (subRectangles.upper_bound(subRecVal - k) != subRectangles.end()) {
                        ans = max(ans, subRecVal - *(subRectangles.upper_bound(subRecVal - k)));
                    }

                    subRectangles.insert(subRecVal);
                }
            }
        }

        return ans;
    }


    int getSubRecVal(vector<vector<int>>& matPreSum, int m, int n, int p, int q) {
        return getMatPreVal(matPreSum, p, q) + getMatPreVal(matPreSum, m - 1, n - 1) - 
            getMatPreVal(matPreSum, m - 1, q) - getMatPreVal(matPreSum, p, n - 1);
    }


    int getMatPreVal(vector<vector<int>>& matPreSum, int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        } else {
            return matPreSum[x][y];
        }
    }


    void initMatPreSum(vector<vector<int>>& matPreSum, vector<vector<int>>& matrix) {
        matPreSum[0][0] = matrix[0][0];

        // Initialize the top row.
        for (int j = 1; j < matrix[0].size(); j++) {
            matPreSum[0][j] = matPreSum[0][j - 1] + matrix[0][j];
        }

        // Initialize the left column.
        for (int i = 1; i < matrix.size(); i++) {
            matPreSum[i][0] = matPreSum[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                matPreSum[i][j] = matPreSum[i - 1][j] + matPreSum[i][j - 1] - matPreSum[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
};


int main() {
    Solution solution;

    vector<vector<int>> matrix;

    vector<int> v1 = {5, -4, -3, 4};
    vector<int> v2 = {-3, -4, 4, 5};
    vector<int> v3 = {5, 1, 5, -4};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);


    solution.maxSumSubmatrix(matrix, 10);
}