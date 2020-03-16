// 337. House Robber III

// Runtime: 24 ms, faster than 43.61% of C++ online submissions for House Robber III.
// Memory Usage: 23 MB, less than 55.56% of C++ online submissions for House Robber III.

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
    unordered_map<TreeNode*, int> m;
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (m.count(root)) return m[root];
        
        int a = rob(root->left) + rob(root->right);
        
        int l = root->left ? rob(root->left->left) + rob(root->left->right) : 0;
        int r = root->right ? rob(root->right->left) + rob(root->right->right) : 0;
        int b = root->val + l + r;
        
        m[root] = max(a, b);
        
        return m[root];
    }
};