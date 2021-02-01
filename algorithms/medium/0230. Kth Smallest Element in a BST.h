// 230. Kth Smallest Element in a BST

// Runtime: 24 ms, faster than 53.27% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 21.6 MB, less than 83.33% of C++ online submissions for Kth Smallest Element in a BST.

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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k, int& ans) {
        if (!root) return;
        inorder(root->left, k, ans);
        --k;
        if (k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }
};