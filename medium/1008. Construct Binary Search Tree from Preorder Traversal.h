// 1008. Construct Binary Search Tree from Preorder Traversal

// Runtime: 12 ms, faster than 5.46% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
// Memory Usage: 10.8 MB, less than 95.24% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i)
            construct(root, preorder[i]);
        return root;
    }
    
    void construct(TreeNode* root, int val) {
        if (root->val < val) {
            if (root->right) construct(root->right, val);
            else root->right = new TreeNode(val);
        } else {
            if (root->left) construct(root->left, val);
            else root->left = new TreeNode(val);
        }
    }
};