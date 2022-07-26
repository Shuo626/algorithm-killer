#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<pair<TreeNode *, size_t>> nodes;
        size_t p_idx, q_idx;
        nodes.push_back({root, 0});
        size_t i = 0;

        while (i < nodes.size())
        {
            TreeNode *tmp = nodes[i].first;

            if (tmp == p)
            {
                p_idx = i;
            }
            if (tmp == q)
            {
                q_idx = i;
            }

            if (tmp->left != nullptr)
            {
                nodes.push_back({tmp->left, i});
            }
            if (tmp->right != nullptr)
            {
                nodes.push_back({tmp->right, i});
            }

            i++;
        }

        while (p_idx != q_idx)
        {
            if (p_idx > q_idx)
            {
                p_idx = nodes[p_idx].second;
            }
            else if (p_idx < q_idx)
            {
                q_idx = nodes[q_idx].second;
            }
        }

        return nodes[p_idx].first;
    }
};
