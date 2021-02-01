// 235. Lowest Common Ancestor of a Binary Search Tree

// Runtime: 36 ms, faster than 83.91% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.2 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        auto x = lowestCommonAncestor(root->left, p, q);
        auto y = lowestCommonAncestor(root->right, p, q);
        if (x && y) return root;
        return x ? x : y;
    }
};