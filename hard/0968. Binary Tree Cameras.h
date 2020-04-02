// 968. Binary Tree Cameras

// Runtime: 8 ms, faster than 90.58% of C++ online submissions for Binary Tree Cameras.
// Memory Usage: 16.3 MB, less than 100.00% of C++ online submissions for Binary Tree Cameras.

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
    int minCameraCover(TreeNode* root) {
        int count = 0;
        install(nullptr, root, count);
        return count;
    }
    
    void install(TreeNode* parent, TreeNode* node, int& count) {
        if (!node) return;
        
        auto left = node->left;
        auto right = node->right;
        
        install(node, left, count);
        install(node, right, count);
        
        if (!parent && node->val == 0) {
            node->val = 2;
            ++count;
            return;
        }
        
        bool has_leaf_child = (left && !left->left && !left->right) || (right && !right->left && !right->right);
        if (has_leaf_child) {
            node->val = 2;
            if (parent) parent->val = 1;
            if (left && left->val == 0) left->val = 1;
            if (right && right->val == 0) right->val = 1;
            ++count;
            return;
        } 
        
        if (!left && !right) {
            return;
        }
        
        if ((left && left->val == 0) || (right && right->val == 0)) {
            node->val = 2;
            if (parent) parent->val = 1;
            if (left && left->val == 0) left->val = 1;
            if (right && right->val == 0) right->val = 1;
            ++count;
            return;
        }
    }
};