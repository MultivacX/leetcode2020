// 653. Two Sum IV - Input is a BST

// Runtime: 36 ms, faster than 89.37% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 24 MB, less than 100.00% of C++ online submissions for Two Sum IV - Input is a BST.

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
	bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        bool ans = false;
        inorder(root, k, root, ans);
        return ans;
    }
    
    void inorder(TreeNode* root, int k, TreeNode* node, bool& ans) {
        if (!node) return;
        if (ans) return;
        inorder(root, k, node->left, ans);
        if (node->val * 2 != k && find(root, k - node->val)) {
            ans = true;
            return;
        }
        inorder(root, k, node->right, ans);
    }
    
    bool find(TreeNode* root, int v) {
        if (!root) return false;
        int diff = v - root->val;
        if (diff < 0) return find(root->left, v);
        if (diff > 0) return find(root->right, v);
        return true;
    }

	// WRONG: 
	// L + root, root + R, L, R, L + R
    /*bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        return find(root->left, k - root->val) 
            || find(root->right, k - root->val)
            || findTarget(root->left, k) 
            || findTarget(root->right, k);
    }*/
};