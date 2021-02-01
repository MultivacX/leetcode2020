// 226. Invert Binary Tree

// Runtime: 4 ms, faster than 65.53% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 10.2 MB, less than 5.45% of C++ online submissions for Invert Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root)  {
            auto l = invertTree(root->right);
            auto r = invertTree(root->left);
            root->left = l;
            root->right = r;
        }
        return root;
    }
};