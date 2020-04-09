// 671. Second Minimum Node In a Binary Tree

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.

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
    int findSecondMinimumValue(TreeNode* root) {
        find(root);
        return s.size() == 2 ? *(--s.end()) : -1;
    }
    
    set<int> s;
    
    void find(TreeNode* root) {
        if (!root || !root->left) return;
        
        s.insert(root->left->val);
        s.insert(root->right->val);
        while (s.size() > 2) s.erase(--s.end());
        
        find(root->left);
        find(root->right);
    }
};