// 1373. Maximum Sum BST in Binary Tree

// Runtime: 460 ms, faster than 9.10% of C++ online submissions for Maximum Sum BST in Binary Tree.
// Memory Usage: 161.5 MB, less than 100.00% of C++ online submissions for Maximum Sum BST in Binary Tree.

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
    int maxSumBST(TreeNode* root) {
        f(root);
        return sum;
    }
    
    unordered_map<TreeNode*, bool> bsts;
    unordered_map<TreeNode*, int> sums;
    int sum = 0;
    
    void f(TreeNode* root) {
        if (!root) return;
        
        f(root->left);
        f(root->right);
        
        if (!root->left && !root->right) {
            bsts[root] = true;
            sums[root] = root->val;
            sum = max(sum, sums[root]);
        } else if (root->left && !root->right) {
            bsts[root] = root->val > root->left->val && bsts[root->left];
            sums[root] = bsts[root] ? root->val + sums[root->left] : 0;
            sum = max(sum, sums[root]);
        } else if (!root->left && root->right) {
            bsts[root] = root->val < root->right->val && bsts[root->right];
            sums[root] = bsts[root] ? root->val + sums[root->right] : 0;
            sum = max(sum, sums[root]);
        } else {
            bsts[root] = root->val > root->left->val && bsts[root->left] && root->val < root->right->val && bsts[root->right];
            sums[root] = bsts[root] ? root->val + sums[root->left] + sums[root->right] : 0;
            sum = max(sum, sums[root]);
        }
    }
};