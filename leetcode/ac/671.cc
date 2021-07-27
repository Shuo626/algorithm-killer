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
    int ans, minest;
    bool flag;


    int findSecondMinimumValue(TreeNode* root) {
        minest = root->val;
        flag = false;
        ans = INT_MAX;

        dfs(root);

        if (flag) {
            return ans;
        } else {
            return -1;
        }
    }


    void dfs(TreeNode *n) {
        if (n == nullptr) {
            return;
        }

        updateMin(n->val);
        dfs(n->left);
        dfs(n->right);
    }


    void updateMin(int x) {
        if (x > minest) {
            ans = min(ans, x);
            flag = true;
        }
    }
};