// 1120. Maximum Average Subtree
// https://leetcode.com/problems/maximum-average-subtree/

// Runtime: 16 ms, faster than 87.52% of C++ online submissions for Maximum Average Subtree.
// Memory Usage: 22.4 MB, less than 86.77% of C++ online submissions for Maximum Average Subtree.
    
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
    double ans = 0;
    
    pair<int, int> sum(TreeNode* root) {
        if (!root) return {0, 0};
        
        int s = root->val, c = 1;
        auto l = sum(root->left);
        s += l.first; c += l.second;
        auto r = sum(root->right);
        s += r.first; c += r.second;
        ans = max(ans, (double)s / (double)c);
        return {s, c};
    }
    
public:
    double maximumAverageSubtree(TreeNode* root) {
        sum(root);
        return ans;
    }
};