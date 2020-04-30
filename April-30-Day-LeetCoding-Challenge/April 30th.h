// the 30-Day LeetCoding Challenge for the month of April
// April 30th, 2020

// Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

// Runtime: 92 ms
// Memory Usage: 48.9 MB

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
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isValid(root, arr, 0);
    }
    
    bool isValid(TreeNode* root, vector<int>& arr, int idx) {
        if (root && !root->left && !root->right && idx + 1 == arr.size() && root->val == arr[idx]) return true;
        if (!root) return false;
        if (idx >= arr.size()) return false;
        if (root->val != arr[idx]) return false;
        return isValid(root->left, arr, idx + 1) || isValid(root->right, arr, idx + 1);
    }
};