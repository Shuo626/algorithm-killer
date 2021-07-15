#include <bits/stdc++.h>


using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> nodes;
    int ans = 0x3fffffff;

    int minDiffInBST(TreeNode *root) {
        dfs(root);

        for (int i = 1; i < nodes.size(); i++) {
            ans = min(ans, abs(nodes[i] - nodes[i - 1]));
        }

        return ans;
    }


    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
};