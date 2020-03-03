// 998. Maximum Binary Tree II

// Runtime: 4 ms, faster than 89.12% of C++ online submissions for Maximum Binary Tree II.
// Memory Usage: 13.5 MB, less than 20.00% of C++ online submissions for Maximum Binary Tree II.

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        } else if (val > root->val) {
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;   
        }
    }
};