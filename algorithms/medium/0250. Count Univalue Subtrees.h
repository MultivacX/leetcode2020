// 250. Count Univalue Subtrees
// https://leetcode.com/problems/count-univalue-subtrees/

// Runtime: 20 ms, faster than 17.98% of C++ online submissions for Count Univalue Subtrees.
// Memory Usage: 16.9 MB, less than 42.70% of C++ online submissions for Count Univalue Subtrees.
    
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int cnt = 0;
    
    bool isUni(TreeNode* root) {
        if (!root) return true;
        
        bool l = isUni(root->left);
        bool r = isUni(root->right);
        
        if (l && r) {
            if (!root->left && !root->right) {
                ++cnt;
                return true;
            } else if (!root->right && root->left && root->left->val == root->val) {
                ++cnt;
                return true;
            } else if (!root->left && root->right && root->right->val == root->val) {
                ++cnt;
                return true;
            } else if (root->left && root->right && root->left->val == root->val && root->right->val == root->val) {
                ++cnt;
                return true;
            }
        }
        
        return false;
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        isUni(root);
        return cnt;
    }
};