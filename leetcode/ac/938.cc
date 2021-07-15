#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumBST(root, low, high);
    }


    int sumBST(TreeNode* n, int& low, int& high) {
        if (n == nullptr) {
            return 0;
        }

        int left, right;

        left = sumBST(n->left, low, high);
        right = sumBST(n->right, low, high);

        if (n->val >= low && n->val <= high) {
            return left + right + n->val;
        } else {
            return left + right;
        }
    }
};
