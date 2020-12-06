// 298. Binary Tree Longest Consecutive Sequence
// Runtime: 52 ms, faster than 43.23% of C++ online submissions for Binary Tree Longest Consecutive Sequence.
// Memory Usage: 34.5 MB, less than 12.87% of C++ online submissions for Binary Tree Longest Consecutive Sequence.
    
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
    
    int helper(TreeNode* root) {
        if (!root) return 0;
        // if (!root->left && !root->right) return 1;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int cnt = 1;
        if (root->left && root->left->val == root->val + 1)
            cnt = 1 + l;
        if (root->right && root->right->val == root->val + 1)
            cnt = max(cnt, 1 + r);
        ans = max(max(ans, cnt), max(l, r));
        return cnt;
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return ans;
    }
};