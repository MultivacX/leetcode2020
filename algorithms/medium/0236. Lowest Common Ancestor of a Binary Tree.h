// 236. Lowest Common Ancestor of a Binary Tree

// Runtime: 20 ms, faster than 75.75% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 16.5 MB, less than 98.18% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

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
        if (root == nullptr || root == p || root == q) return root;
        auto tp = lowestCommonAncestor(root->left, p, q);
        auto tq = lowestCommonAncestor(root->right, p, q);
        if (tp && tq) return root;
        return tp ? tp : tq;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p) return p;
        if (root == q) return q;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        return l ? l : r;
    }
};