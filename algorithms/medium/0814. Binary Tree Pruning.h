// 814. Binary Tree Pruning

// Runtime: 4 ms, faster than 64.90% of C++ online submissions for Binary Tree Pruning.
// Memory Usage: 9.7 MB, less than 92.86% of C++ online submissions for Binary Tree Pruning.

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
    TreeNode* pruneTree(TreeNode* root) {
        int sum = p(root, nullptr);
        return sum == 0 ? nullptr : root;
    }
    
    int p(TreeNode* node, TreeNode* parent) {
        if (!node) return 0;
        int l = p(node->left, node);
        int r = p(node->right, node);
        int sum = l + r + node->val;
        if (sum == 0) {
            if (!parent) {
            } else if (node == parent->left) {
                parent->left = nullptr;
            } else if (node == parent->right) {
                parent->right = nullptr;
            }
            //delete node;
        }
        return sum;
    }
};