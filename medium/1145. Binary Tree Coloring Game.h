// 1145. Binary Tree Coloring Game

// Runtime: 4 ms, faster than 72.06% of C++ online submissions for Binary Tree Coloring Game.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Binary Tree Coloring Game.

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        find(root, x);
        // x's parent, x,  x's left, x's right
        // p_count   + 1 + l_count + r_count
        p_count = n - 1 - l_count - r_count;
        return p_count > (1 + l_count + r_count) || l_count > (1 + p_count + r_count) || r_count > (1 + l_count + p_count);
    }
    
    int p_count = 0;
    int l_count = 0;
    int r_count = 0;
    
    bool find(TreeNode* root, int x) {
        if (!root) return false;
        
        if (root->val == x) {
            l_count = count(root->left);
            r_count = count(root->right);
            return true;
        } else {
            return find(root->left, x) || find(root->right, x);
        }
    }
    
    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};