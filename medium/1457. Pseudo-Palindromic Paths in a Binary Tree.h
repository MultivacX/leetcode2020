// 1457. Pseudo-Palindromic Paths in a Binary Tree
// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/

// Runtime: 240 ms, faster than 73.77% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
// Memory Usage: 107.2 MB, less than 82.77% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.

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
    
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> nums(10, 0);
        dfs(root, nums);
        return cnt;
    }
    
    void dfs(TreeNode* node, vector<int>& nums) {
        ++nums[node->val];
        if (!node->left && !node->right) {
            int odd = 0;
            for (int i = 1; i <= 9; ++i)  {
                if (nums[i] & 1) ++odd;
                // if (nums[i]) cout << i << ":" << nums[i] << " ";
            }
            // cout << endl;
            if (odd <= 1) ++cnt;
        } else {
            if (node->left) dfs(node->left, nums);
            if (node->right) dfs(node->right, nums);   
        }
        --nums[node->val];
    }
};