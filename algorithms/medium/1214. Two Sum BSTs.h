// 1214. Two Sum BSTs
// https://leetcode.com/problems/two-sum-bsts/

// Runtime: 36 ms, faster than 96.68% of C++ online submissions for Two Sum BSTs.
// Memory Usage: 29.2 MB, less than 63.99% of C++ online submissions for Two Sum BSTs.
    
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
    bool helper(TreeNode* root1, TreeNode* root2, int target) {
        if (!root1) return false;
        return find(root2, target - root1->val) ||
            helper(root1->left, root2, target) ||
            helper(root1->right, root2, target);
    }
    
    bool find(TreeNode* root2, int target) {
        if (!root2) return false;
        if (root2->val == target) return true;
        return root2->val < target ?
            find(root2->right, target) :
            find(root2->left, target);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return helper(root1, root2, target);
    }
};