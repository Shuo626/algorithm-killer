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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        auto preorder_root_index = new int(0);
        return build(preorder_root_index, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *build(int *preorder_root_index, int l, int r, vector<int> &preorder, vector<int> &inorder)
    {
        if (l > r)
        {
            return nullptr;
        }

        auto node = new TreeNode(preorder[*preorder_root_index]);

        int inorder_root_index;
        for (int i = l; i <= r; i++)
        {
            if (inorder[i] == preorder[*preorder_root_index])
            {
                inorder_root_index = i;
                break;
            }
        }

        *preorder_root_index += 1;

        node->left = build(preorder_root_index, l, inorder_root_index - 1, preorder, inorder);
        node->right = build(preorder_root_index, inorder_root_index + 1, r, preorder, inorder);

        return node;
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    auto tree = sol.buildTree(preorder, inorder);
}
