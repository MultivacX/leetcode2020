// 538. Convert BST to Greater Tree

// Runtime: 60 ms, faster than 23.64% of C++ online submissions for Convert BST to Greater Tree.
// Memory Usage: 27.3 MB, less than 14.29% of C++ online submissions for Convert BST to Greater Tree.

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
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        convert(root, val);
        return root;
    }
    
    void convert(TreeNode* root, int& val) {
        if (!root) return;
        convert(root->right, val);
        val += root->val;
        root->val = val;
        convert(root->left, val);
    }
};