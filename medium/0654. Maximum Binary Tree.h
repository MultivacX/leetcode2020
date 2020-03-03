// 654. Maximum Binary Tree

// Runtime: 96 ms, faster than 75.62% of C++ online submissions for Maximum Binary Tree.
// Memory Usage: 34.2 MB, less than 19.44% of C++ online submissions for Maximum Binary Tree.

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return nullptr;
        
        auto root = new TreeNode(nums[0]);
        for (int i = 1; i < n; ++i) 
            root = insert(root, nums[i]);
        return root;
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) 
            return new TreeNode(val);
        
        if (root->val < val) {
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        root->right = insert(root->right, val);
        return root;
    }
};