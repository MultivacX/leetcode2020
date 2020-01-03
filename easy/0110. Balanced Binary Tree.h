// 110. Balanced Binary Tree

// Runtime: 24 ms, faster than 9.15% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 25.7 MB, less than 8.48% of C++ online submissions for Balanced Binary Tree.

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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        count(root);
        return _isBalanced(root);
    }
    
    map<TreeNode*, int> levels;
    int count(TreeNode* root) {
        if (!root) return 0;
        levels[root] = 1 + max(count(root->left), count(root->right));
        return levels[root];
    }
    
    bool _isBalanced(TreeNode* root) {
        if (!root) return true;
        int l = root->left ? levels[root->left] : 0;
        int r = root->right ? levels[root->right] : 0;
        return abs(l - r) <= 1 && _isBalanced(root->left) && _isBalanced(root->right);
    }
    
    /* misunderstand
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int num = 0;
        int levels = count(root, num);
        if (num == (1 << levels) - 1) return true;
        if (num < (1 << (levels - 1))) return false;
        
        num = 0;
        count0(root, levels - 1, num);
        return num == (1 << (levels - 1)) - 1;
    }
    
    int count(TreeNode* root, int& num) {
        if (!root) return 0;
        ++num;
        return 1 + max(count(root->left, num), count(root->right, num));
    }
    
    void count0(TreeNode* root, int level, int& num) {
        if (!root || level <= 0) return;
        ++num;
        --level;
        count0(root->left, level, num);
        count0(root->right, level, num);
    }*/
};