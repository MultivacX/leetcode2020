// 965. Univalued Binary Tree

// Runtime: 4 ms, faster than 60.11% of C++ online submissions for Univalued Binary Tree.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Univalued Binary Tree.

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
    bool isUnivalTree(TreeNode* root) {
        return !root || isUnivalTree(root, root->val);
    }
    
    bool isUnivalTree(TreeNode* root, int val) {
        return !root || (root->val == val && isUnivalTree(root->left, val) && isUnivalTree(root->right, val));
    }
};