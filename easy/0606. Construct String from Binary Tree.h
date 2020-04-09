// 606. Construct String from Binary Tree

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Construct String from Binary Tree.
// Memory Usage: 18.4 MB, less than 100.00% of C++ online submissions for Construct String from Binary Tree.

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
    string tree2str(TreeNode* t) {
        ostringstream oss;
        construct(t, oss);
        return oss.str();
    }
    
    void construct(TreeNode* t, ostringstream& oss) {
        if (!t) return;
        
        oss << t->val;
        
        if (t->left) {
            oss << "(";
            construct(t->left, oss);
            oss << ")";
        } 
        
        if (t->right) {
            if (!t->left) oss << "()";
            oss << "(";
            construct(t->right, oss);
            oss << ")";
        } 
    }
};