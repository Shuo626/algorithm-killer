#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(vector<TreeNode *> &nodes, TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        nodes.push_back(node);
        dfs(nodes, node->left);
        dfs(nodes, node->right);
    }

    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        vector<TreeNode *> nodes;
        dfs(nodes, root);

        for (size_t i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};
