// 513. Find Bottom Left Tree Value

// Runtime: 8 ms, faster than 99.17% of C++ online submissions for Find Bottom Left Tree Value.
// Memory Usage: 20.1 MB, less than 100.00% of C++ online submissions for Find Bottom Left Tree Value.

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
    int findBottomLeftValue(TreeNode* root) {
        int val = root->val;
        int row = 0;
        find(root, 0, val, row);
        return val;
    }
    
    void find(TreeNode* root, int cur_row, int& val, int& row) {
        if (!root) return;
        
        find(root->left, cur_row + 1, val, row);
        if (!root->left && !root->right && cur_row > row) {
            val = root->val;
            row = cur_row;
        }
        find(root->right, cur_row + 1, val, row);
    }
};