// 1469. Find All The Lonely Nodes
// https://leetcode.com/problems/find-all-the-lonely-nodes/

// Runtime: 12 ms, faster than 97.77% of C++ online submissions for Find All The Lonely Nodes.
// Memory Usage: 20.2 MB, less than 97.77% of C++ online submissions for Find All The Lonely Nodes.
    
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
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        
        if (!root->left && root->right) 
            ans.push_back(root->right->val);
        else if (root->left && !root->right) 
            ans.push_back(root->left->val);
        
        helper(root->left, ans);
        helper(root->right, ans);
    }
    
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};