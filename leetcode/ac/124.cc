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
    long maxVal;


    int maxPathSum(TreeNode* root) {
        maxVal = INT_MIN;

        _maxPathSum(root);

        return maxVal;
    }

    
    long _maxPathSum(TreeNode *n) {
        if (n == nullptr) {
            return INT_MIN;
        }

        long maxLeftVal, maxRightVal;

        maxLeftVal = _maxPathSum(n->left);
        maxRightVal = _maxPathSum(n->right);

        maxVal = max(maxVal, max4(maxLeftVal + n->val, maxRightVal + n->val, maxLeftVal + maxRightVal + n->val, n->val));

        return max3(maxLeftVal + n->val, maxRightVal + n->val, n->val);
    }

    long max3(long a, long b, long c) {
        return max(max(a, b), c);
    }

    long max4(long a, long b, long c, long d) {
        return max(a, max3(b, c, d));
    }
};