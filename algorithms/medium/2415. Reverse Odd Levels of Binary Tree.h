// 2415. Reverse Odd Levels of Binary Tree
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

// Runtime: 497 ms, faster than 52.96% of C++ online submissions for Reverse Odd Levels of Binary Tree.
// Memory Usage: 75.5 MB, less than 60.94% of C++ online submissions for Reverse Odd Levels of Binary Tree.

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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        vector<TreeNode *> v{root};
        int lv = 0;
        while (!v.empty())
        {
            int i = 0, j = v.size() - 1;
            if (lv & 1)
                while (i < j)
                {
                    swap(v[i]->val, v[j]->val);
                    ++i, --j;
                }
            ++lv;

            if (v[0]->left == nullptr)
                break;

            vector<TreeNode *> t;
            for (auto node : v)
            {
                t.push_back(node->left);
                t.push_back(node->right);
            }
            swap(v, t);
        }
        return root;
    }
};