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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> tree;

        dfs(tree, root);

        TreeNode *n, *last;
        n = new TreeNode(tree[0]);
        last = n;

        for (int i = 1; i < tree.size(); i++) {
            TreeNode *tmp;

            tmp = new TreeNode(tree[i]);
            last->right = tmp;

            last = tmp;
        }

        return n;
    }


    void dfs(vector<int>& tree, TreeNode *n) {
        if (n == nullptr) {
            return;
        }

        dfs(tree, n->left);
        tree.push_back(n->val);
        dfs(tree, n->right);
    }
};