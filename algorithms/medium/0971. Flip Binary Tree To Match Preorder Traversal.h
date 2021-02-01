// 971. Flip Binary Tree To Match Preorder Traversal

// Runtime: 4 ms, faster than 85.78% of C++ online submissions for Flip Binary Tree To Match Preorder Traversal.
// Memory Usage: 11.9 MB, less than 71.43% of C++ online submissions for Flip Binary Tree To Match Preorder Traversal.

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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        vector<int> flipped;
        preorder(root, voyage, i, flipped);
        if (!flipped.empty() && flipped[0] == -1) return {-1};
        if (i != voyage.size()) return {-1};
        return flipped;
    }
    
    void preorder(TreeNode* root, const vector<int>& voyage, int& i, vector<int>& flipped) {
        if (root && i < voyage.size()) {
            if (root->val != voyage[i++]) {
                flipped = {-1};
                return;
            } 
              
            if (i < voyage.size()) {
                if (root->left && root->left->val != voyage[i]) {
                    flipped.push_back(root->val);
                    preorder(root->right, voyage, i, flipped);
                    preorder(root->left, voyage, i, flipped);
                } else {
                    preorder(root->left, voyage, i, flipped);
                    preorder(root->right, voyage, i, flipped);
                }
            }
        }
    }
};