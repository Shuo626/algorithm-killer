#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int isStep[300][300];
    int rows, cols;

    struct Index {
        int i;
        int j;
    };
    typedef struct Index Index;


    int numIslands(vector<vector<char>>& grid) {
        int ans;
        ans = 0;

        rows = grid.size();
        cols = grid[0].size();
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (isStep[i][j] || grid[i][j] == '0') {
                    continue;
                }

                Index idx;
                idx.i = i;
                idx.j = j;
                walkIsland(grid, idx);
                ans += 1;
            }
        }

        return ans;
    }

    void walkIsland(vector<vector<char>>& grid, Index startIdx) {
        queue<Index> que;

        que.push(startIdx);

        while (!que.empty()) {
            Index idx, tmp;
            
            idx = que.front();
            que.pop();
            isStep[idx.i][idx.j] = 1;

            if (idx.i + 1 < rows && grid[idx.i + 1][idx.j] == '1' && !isStep[idx.i + 1][idx.j]) {
                tmp.i = idx.i + 1;
                tmp.j = idx.j;
                que.push(tmp);
                isStep[tmp.i][tmp.j] = 1;
            }

            if (idx.j + 1 < cols && grid[idx.i][idx.j + 1] == '1' && !isStep[idx.i][idx.j + 1]) {
                tmp.i = idx.i;
                tmp.j = idx.j + 1;
                que.push(tmp);
                isStep[tmp.i][tmp.j] = 1;
            }

            if (idx.j - 1 >= 0 && grid[idx.i][idx.j - 1] == '1' && !isStep[idx.i][idx.j - 1]) {
                tmp.i = idx.i;
                tmp.j = idx.j - 1;
                que.push(tmp);
                isStep[tmp.i][tmp.j] = 1;
            }

            if (idx.i - 1 >= 0 && grid[idx.i - 1][idx.j] == '1' && !isStep[idx.i - 1][idx.j]) {
                tmp.i = idx.i - 1;
                tmp.j = idx.j;
                que.push(tmp);
                isStep[tmp.i][tmp.j] = 1;
            }
            
        }
    }
};


int main() {
    vector<vector<char>> grid;
    vector<char> a = {'1','1','1','1','0'};
    grid.push_back(a);
    a = {'1','1','0','1','0'};
    grid.push_back(a);
    a = {'1','1','0','0','0'};
    grid.push_back(a);
    a = {'0','0','0','0','0'};
    grid.push_back(a);

    Solution solution;
    cout << solution.numIslands(grid) << endl;
}