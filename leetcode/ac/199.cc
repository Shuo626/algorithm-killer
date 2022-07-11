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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> rightNodes;
        if (root == NULL)
        {
            return rightNodes;
        }

        vector<pair<TreeNode *, int>> nodes;
        nodes.push_back({root, 0});
        int p = 0;

        while (p < nodes.size())
        {
            auto node = nodes[p];

            if (node.first->left != NULL)
            {
                nodes.push_back({node.first->left, node.second + 1});
            }
            if (node.first->right != NULL)
            {
                nodes.push_back({node.first->right, node.second + 1});
            }

            p += 1;
        }

        for (int i = 1; i < nodes.size(); i++)
        {
            if (nodes[i].second != nodes[i - 1].second)
            {
                rightNodes.push_back(nodes[i - 1].first->val);
            }
        }

        rightNodes.push_back(nodes.back().first->val);

        return rightNodes;
    }
};
