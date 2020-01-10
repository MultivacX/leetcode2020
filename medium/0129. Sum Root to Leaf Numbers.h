// 129. Sum Root to Leaf Numbers

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 12.4 MB, less than 92.31% of C++ online submissions for Sum Root to Leaf Numbers.

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
    int ans;
    
    int sumNumbers(TreeNode* root) {
        ans = 0;
        sum(root, 0);
        return ans;
    }
    
    void sum(TreeNode* root, int v) {
        if (!root) return;
        v = v * 10 + root->val;
        if (!root->left && !root->right) {
            ans += v;
            return;
        }
        sum(root->left, v);
        sum(root->right, v);
    }
};