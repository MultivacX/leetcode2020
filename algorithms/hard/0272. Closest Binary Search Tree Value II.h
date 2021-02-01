// 272. Closest Binary Search Tree Value II
// https://leetcode.com/problems/closest-binary-search-tree-value-ii/

// Runtime: 16 ms, faster than 71.48% of C++ online submissions for Closest Binary Search Tree Value II.
// Memory Usage: 22.2 MB, less than 78.86% of C++ online submissions for Closest Binary Search Tree Value II.
    
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
    vector<int> ans;
    int start = 0;
    
    void inorder(TreeNode* root, double target, int k) {
        if (!root) return;
        
        inorder(root->left, target, k);
        if (ans.size() < k) {
            ans.push_back(root->val);
        } else if (abs((double)ans[ans.size() - k] - target) > abs((double)root->val - target)) {
            ++start;
            ans.push_back(root->val);
        } else {
            return;
        }
        inorder(root->right, target, k);
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorder(root, target, k);
        if (ans.size() == k) return ans;
        
        vector<int> res(k);
        for (int i = 0; i < k; ++i) 
            res[i] = ans[start + i];
        return res;
    }
};