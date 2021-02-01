// 1038. Binary Search Tree to Greater Sum Tree

// Runtime: 4 ms, faster than 59.06% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.

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
    TreeNode* bstToGst(TreeNode* root) {
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