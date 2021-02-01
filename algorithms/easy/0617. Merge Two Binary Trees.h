// 617. Merge Two Binary Trees

// Runtime: 48 ms, faster than 87.65% of C++ online submissions for Merge Two Binary Trees.
// Memory Usage: 24.8 MB, less than 5.55% of C++ online submissions for Merge Two Binary Trees.

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        delete t2;
        return t1;
    }
};