// 1325. Delete Leaves With a Given Value

// Runtime: 28 ms, faster than 23.80% of C++ online submissions for Delete Leaves With a Given Value.
// Memory Usage: 21.6 MB, less than 100.00% of C++ online submissions for Delete Leaves With a Given Value.

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return find(root, target);
    }
    
    TreeNode* find(TreeNode* node, int target) {
        if (!node) return nullptr;
        
        node->left = find(node->left, target);
        node->right = find(node->right, target);
        
        if (!node->left && !node->right && node->val == target) {
            //delete node;
            node = nullptr;
        }
        return node;
    }
};