// 700. Search in a Binary Search Tree

// Runtime: 52 ms, faster than 71.43% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 26.8 MB, less than 100.00% of C++ online submissions for Search in a Binary Search Tree.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};