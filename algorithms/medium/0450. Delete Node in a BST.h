// 450. Delete Node in a BST

// Runtime: 52 ms, faster than 45.86% of C++ online submissions for Delete Node in a BST.
// Memory Usage: 29 MB, less than 5.41% of C++ online submissions for Delete Node in a BST.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            auto l = root->left;
            auto r = root->right;
            delete root;
            if (l) root = insert(l, r);
            else root = r;
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* root, TreeNode* node) {
        auto p = root;
        while (p->right) p = p->right;
        p->right = node;
        return root;
    }
};