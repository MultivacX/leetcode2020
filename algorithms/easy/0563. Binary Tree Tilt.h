// 563. Binary Tree Tilt

// Runtime: 16 ms, faster than 92.78% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 19.2 MB, less than 100.00% of C++ online submissions for Binary Tree Tilt.

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
    int findTilt(TreeNode* root) {
        sum(root);
        return tilt;
    }
    
    int tilt = 0;
    int sum(TreeNode* root) {
        if (!root) return 0;
        
        int l = sum(root->left);
        int r = sum(root->right);
        tilt += abs(l - r);
        return root->val + l + r;
    }
};