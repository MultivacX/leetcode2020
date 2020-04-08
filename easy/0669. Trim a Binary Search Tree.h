// 669. Trim a Binary Search Tree

// Runtime: 20 ms, faster than 70.82% of C++ online submissions for Trim a Binary Search Tree.
// Memory Usage: 19.3 MB, less than 100.00% of C++ online submissions for Trim a Binary Search Tree.

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim_greater(trim_less(root, L), R);
    }
    
    TreeNode* trim_less(TreeNode* root, int L) {
        if (!root) return nullptr;
        if (root->val < L) return trim_less(root->right, L);
        if (root->val > L) {
            root->left = trim_less(root->left, L);
            return root;
        }
        root->left = nullptr;
        return root;
    }
    
    TreeNode* trim_greater(TreeNode* root, int R) {
        if (!root) return nullptr;
        if (root->val > R) return trim_greater(root->left, R);
        if (root->val < R) {
            root->right = trim_greater(root->right, R);
            return root;
        }
        root->right = nullptr;
        return root;
    }
};