// 951. Flip Equivalent Binary Trees

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Flip Equivalent Binary Trees.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Flip Equivalent Binary Trees.

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return !root1 && !root2;
        if (root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};


class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // cout << (root1 ? to_string(root1->val) : "X") << " --- ";
        // cout << (root2 ? to_string(root2->val) : "X") << endl;
        if (!root1 || !root2) return root1 == root2;
        if (root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) or
               (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
    }
};