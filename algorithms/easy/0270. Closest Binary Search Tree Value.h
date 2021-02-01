// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/

// Runtime: 16 ms, faster than 57.98% of C++ online submissions for Closest Binary Search Tree Value.
// Memory Usage: 21.5 MB, less than 62.89% of C++ online submissions for Closest Binary Search Tree Value.
    
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
    double diff = INT_MAX * 2.0;
    int ans;
    
    void find(TreeNode* root, double t) {
        if (!root) return;
        
        if (root->val >= t) find(root->left, t);
        double d = abs((double)root->val - t);
        if (d < diff) {
            diff = d;
            ans = root->val;
        }
        if (root->val < t) find(root->right, t);
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        find(root, target);
        return ans;
    }
};