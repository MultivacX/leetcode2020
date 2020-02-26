// 404. Sum of Left Leaves

// Runtime: 4 ms, faster than 83.79% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.5 MB, less than 63.64% of C++ online submissions for Sum of Left Leaves.

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
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(nullptr, root);
    }
    
    int sum(TreeNode* parent, TreeNode* node) {
        if (!node) return 0;
        if (!parent || parent->right == node || node->left || node->right) return sum(node, node->left) + sum(node, node->right);
        return node->val;
    }
};