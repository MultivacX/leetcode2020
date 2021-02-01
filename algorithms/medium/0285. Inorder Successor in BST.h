// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

// Runtime: 44 ms, faster than 5.69% of C++ online submissions for Inorder Successor in BST.
// Memory Usage: 23.5 MB, less than 20.17% of C++ online submissions for Inorder Successor in BST.
    
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
    TreeNode* q = nullptr;
    TreeNode* pre = nullptr;
    
    void re_inorder(TreeNode* root, TreeNode* p) {
        if (!root) return;
        
        re_inorder(root->right, p);
        if (root == p) {
            q = pre;
            return;
        }
        pre = root;
        re_inorder(root->left, p);
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        re_inorder(root, p);
        return q;
    }
};