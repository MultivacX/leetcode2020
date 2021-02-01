// 701. Insert into a Binary Search Tree

// Runtime: 128 ms, faster than 8.03% of C++ online submissions for Insert into a Binary Search Tree.
// Memory Usage: 50.1 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto node = new TreeNode(val);
        if (!root) return node;
        return insert(root, node);
    }
    
    TreeNode* insert(TreeNode* root, TreeNode* node) {
        if (root->val < node->val) {
            if (root->right) {
                root->right = insert(root->right, node);
            } else {
                root->right = node;
            }
        } else {
            if (root->left) {
                root->left = insert(root->left, node);
            } else {
                root->left = node;
            }
        }
        return root;
    }
};