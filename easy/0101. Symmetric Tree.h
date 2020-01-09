// 101. Symmetric Tree

// Runtime: 4 ms, faster than 84.24% of C++ online submissions for Symmetric Tree.
// Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Symmetric Tree.

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l && r) return false;
        if (l && !r) return false;
        if (l->val != r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};