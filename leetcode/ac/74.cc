#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    struct Index {
        int i;
        int j;
    };
    typedef struct Index Index;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLen, colLen;
        int totalLen;

        rowLen = matrix.size();
        colLen = matrix[0].size();
        totalLen = rowLen * colLen;

        return search(0, totalLen - 1, target, rowLen, colLen, matrix);
    }

    bool search(int l, int r, int target, int rowLen, int colLen, vector<vector<int>>& matrix) {
        if (l > r) {
            return false;
        }

        int mid;
        mid = (l + r) / 2;

        Index idx;
        idx = getIndex(mid, rowLen, colLen);

        int tmp;
        tmp = matrix[idx.i][idx.j];

        if (target == tmp) {
            return true;
        } else if (target < tmp) {
            return search(l, mid - 1, target, rowLen, colLen, matrix);
        } else {
            return search(mid + 1, r, target, rowLen, colLen, matrix);
        }
    }

    Index getIndex(int mid, int rowLen, int colLen) {
        Index idx;
        idx.i = upRound(mid + 1, colLen) - 1; 
        idx.j = mid + 1 - idx.i * colLen - 1;

        return idx;
    }

    int upRound(int a, int b) {
        return (a + b - 1) / b;
    }
};