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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<pair<int, TreeNode *>> que;
        vector<vector<int>> rst;

        if (root != NULL)
        {
            que.push({0, root});
        }

        while (que.size())
        {
            auto node = que.front();
            que.pop();

            if (rst.size() == node.first)
            {
                vector<int> tmp;
                rst.push_back(move(tmp));
            }

            rst[node.first].push_back(node.second->val);

            if (node.second->left != NULL)
            {
                que.push({node.first + 1, node.second->left});
            }
            if (node.second->right != NULL)
            {
                que.push({node.first + 1, node.second->right});
            }
        }

        return rst;
    }
};

int main()
{
    TreeNode root = {3};
    Solution sol;

    auto rst = sol.levelOrder(&root);
    cout << rst[0][0];
}
