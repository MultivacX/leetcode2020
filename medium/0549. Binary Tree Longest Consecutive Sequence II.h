// 549. Binary Tree Longest Consecutive Sequence II
// Runtime: 20 ms, faster than 46.77% of C++ online submissions for Binary Tree Longest Consecutive Sequence II.
// Memory Usage: 23.6 MB, less than 47.85% of C++ online submissions for Binary Tree Longest Consecutive Sequence II.
    
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
    int ans = 1;
    
    pair<int, int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto l = helper(root->left);
        auto r = helper(root->right);
        
        int cnti = 0, cntd = 0;
        if (root->left) {
            if (root->left->val == root->val + 1) cnti = l.first;
            else if (root->left->val == root->val - 1) cntd = l.second;
        }
            
        if (root->right) {
            if (root->right->val == root->val + 1) cnti = max(cnti, r.first);
            else if (root->right->val == root->val - 1) cntd = max(cntd, r.second);
        }
        ans = max(ans, cnti + 1 + cntd);
        return {cnti + 1, cntd + 1};
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return ans;
    }
};