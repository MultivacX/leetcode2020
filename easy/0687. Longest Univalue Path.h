// 687. Longest Univalue Path

// Runtime: 148 ms, faster than 36.33% of C++ online submissions for Longest Univalue Path.
// Memory Usage: 47 MB, less than 100.00% of C++ online submissions for Longest Univalue Path.

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
    int longestUnivaluePath(TreeNode* root) {
        find_path(root);
        return ans;
    }
    
    int ans = 0;
    
    int find_path(TreeNode* root) {
        if (!root) return 0;
        
        int L = 0;
        if (root->left && root->left->val == root->val) L = 1 + find_path(root->left);    
        else find_path(root->left);
        
        int R = 0;
        if (root->right && root->right->val == root->val) R = 1 + find_path(root->right);    
        else find_path(root->right);
        
        ans = max(ans, L + R);
        return max(L, R);
    }
};