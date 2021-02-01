// 783. Minimum Distance Between BST Nodes

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.

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
    int minDiffInBST(TreeNode* root) {
        diff(root);
        return ans;
    }
    
    int ans = INT_MAX;
    int val = -1;
    
    void diff(TreeNode* root) {
        if (!root) return;
        
        diff(root->left);
        if (val == -1) val = root->val;
        else {
            ans = min(ans, root->val - val);
            val = root->val;
        }
        diff(root->right);
    }
};