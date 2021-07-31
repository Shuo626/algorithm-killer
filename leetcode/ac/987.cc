#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes;

        dfs(root, 0, 0, nodes);
        
        sort(nodes.begin(), nodes.end(), comp);

        vector<vector<int>> ans;
        vector<int> tmp;

        const int row = 0, col = 1, val = 2;

        tmp.push_back(nodes[0][val]);

        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i][col] == nodes[i - 1][col]) {
                tmp.push_back(nodes[i][val]);
            } else {
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(nodes[i][val]);
            }
        }

        ans.push_back(tmp);

        return ans;
    }


    static bool comp(const vector<int>& n1, const vector<int>& n2) {
        const int row = 0, col = 1, val = 2;

        if (n1[col] != n2[col]) {
            return n1[col] < n2[col];
        } else if (n1[row] != n2[row]) {
            return n1[row] < n2[row];
        } else {
            return n1[val] < n2[val];
        }
    }

    void dfs(TreeNode *n, int row, int col, vector<vector<int>>& nodes) {
        if (n == nullptr) {
            return;
        }

        vector<int> triad;

        triad.push_back(row);
        triad.push_back(col);
        triad.push_back(n->val);

        nodes.push_back(triad);

        dfs(n->left, row + 1, col - 1, nodes);
        dfs(n->right, row + 1, col + 1, nodes);
    }
};