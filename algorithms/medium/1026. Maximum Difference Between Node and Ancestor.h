// 1026. Maximum Difference Between Node and Ancestor

// Runtime: 8 ms, faster than 58.87% of C++ online submissions for Maximum Difference Between Node and Ancestor.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Maximum Difference Between Node and Ancestor.

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
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        get_diff(root->left, root->val, root->val, diff);
        get_diff(root->right, root->val, root->val, diff);
        return diff;
    }
    
    void get_diff(TreeNode* root, int max_val, int min_val, int& diff) {
        if (!root) return;
        
        diff = max(diff, abs(root->val - max_val));
        diff = max(diff, abs(root->val - min_val));
        
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        
        get_diff(root->left, max_val, min_val, diff);
        get_diff(root->right, max_val, min_val, diff);
    }
};