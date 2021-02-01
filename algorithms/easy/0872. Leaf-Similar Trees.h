// 872. Leaf-Similar Trees

// Runtime: 4 ms, faster than 71.46% of C++ online submissions for Leaf-Similar Trees.
// Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Leaf-Similar Trees.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        get_leaves(root1, leaves1);
        vector<int> leaves2;
        get_leaves(root2, leaves2);
        return leaves1 == leaves2;
    }
    
    void get_leaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        
        get_leaves(root->left, leaves);
        if (root->left == root->right) leaves.push_back(root->val);
        get_leaves(root->right, leaves);
    }
};