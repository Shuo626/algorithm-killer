#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    const int INDEX = 0, VAL = 1;


    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> heap;

        for (int i = 0; i < mat.size(); i++) {
            addRow(k, i, mat[i], heap);
        }

        vector<int> ans;

        for (vector<int>& pair: heap) {
            ans.push_back(pair[INDEX]);
        }

        return ans;
    }


    void addRow(int k, int index, vector<int>& row, vector<vector<int>>& heap) {
        int val;
        vector<int> pair;

        val = 0;

        for (int& x: row) {
            if (x == 0) {
                break;
            }
            val += x;
        }

        pair.push_back(index);
        pair.push_back(val);

        addHeap(k, pair, heap);
    }


    void addHeap(int k, vector<int>& pair, vector<vector<int>>& heap) {        
        heap.push_back(pair);

        for (int i = heap.size() - 1; i > 0; i--) {
            if (heap[i][VAL] < heap[i  -1][VAL]) {
                swap(heap[i], heap[i - 1]);
            }
        }

        if (heap.size() > k) {
            heap.pop_back();
        }
    }
};


int main() {
    Solution solution;

    vector<vector<int>> mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    solution.kWeakestRows(mat, 3);
}