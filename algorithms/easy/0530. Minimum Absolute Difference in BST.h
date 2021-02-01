// 530. Minimum Absolute Difference in BST

// Runtime: 16 ms, faster than 91.18% of C++ online submissions for Minimum Absolute Difference in BST.
// Memory Usage: 19.4 MB, less than 100.00% of C++ online submissions for Minimum Absolute Difference in BST.

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
    int getMinimumDifference(TreeNode* root) {
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