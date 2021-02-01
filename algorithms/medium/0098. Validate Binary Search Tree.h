// 98. Validate Binary Search Tree

// Runtime: 16 ms, faster than 65.49% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 20.7 MB, less than 68.75% of C++ online submissions for Validate Binary Search Tree.

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
    bool isValidBST(TreeNode* root) {
        int64_t val = (int64_t)INT_MIN - 1;
        return inorder(root, val);
    }
    
    bool inorder(TreeNode* root, int64_t& val) {
        if (!root) return true;
        if (!inorder(root->left, val)) return false;
        // cout << val << ", " << root->val << endl;
        if (val >= root->val) return false;
        val = root->val;
        if (!inorder(root->right, val)) return false;
        return true;
    }
};