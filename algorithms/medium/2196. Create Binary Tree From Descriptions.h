// 2196. Create Binary Tree From Descriptions
// https://leetcode.com/problems/create-binary-tree-from-descriptions/

// Runtime: 1083 ms, faster than 84.36% of C++ online submissions for Create Binary Tree From Descriptions.
// Memory Usage: 257.8 MB, less than 97.19% of C++ online submissions for Create Binary Tree From Descriptions.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int> > &descriptions)
    {
        unordered_map<int, pair<TreeNode *, int> > nodes; // val, node, child
        for (const auto &d : descriptions)
        {
            int p = d[0], c = d[1], l = d[2];

            TreeNode *parent = 0, *child = 0;

            if (nodes.find(p) == nodes.end())
            {
                auto node = new TreeNode(p);
                nodes[p] = {node, 0};
            }
            parent = nodes[p].first;

            if (nodes.find(c) == nodes.end())
            {
                auto node = new TreeNode(c);
                nodes[c] = {node, 1};
            }
            nodes[c].second = 1;
            child = nodes[c].first;

            if (l)
                parent->left = child;
            else
                parent->right = child;
        }

        TreeNode *root = 0;
        for (const auto it : nodes)
        {
            if (!it.second.second)
            {
                root = it.second.first;
                break;
            }
        }
        return root;
    }
};