// 543. Diameter of Binary Tree

// Runtime: 16 ms, faster than 38.56% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 20.2 MB, less than 25.93% of C++ online submissions for Diameter of Binary Tree.

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
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        int h = 0;
        f(root, h);
        return ans;
    }
    
    int ans;
    int f(TreeNode* root, int& h) {
        if (!root) {
            h = 0;
            return 0;
        }
        
        int lh = 0;
        int l = f(root->left, lh);
        int rh = 0;
        int r = f(root->right, rh);
        
        h = (root->left || root->right ? 1 : 0) + max(l, r);
        ans = max(ans, (root->left ? 1 : 0) + (root->right ? 1 : 0) + l + r);
        return h;
    }
};