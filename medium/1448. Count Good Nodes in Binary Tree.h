// 1448. Count Good Nodes in Binary Tree

// Runtime: 188 ms, faster than 97.37% of C++ online submissions for Count Good Nodes in Binary Tree.
// Memory Usage: 86.6 MB, less than 100.00% of C++ online submissions for Count Good Nodes in Binary Tree.

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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        count(root, root->val, ans);
        return ans;
    }
    
    void count(TreeNode* root, int max_val, int& ans) {
        if (!root) return;
        if (max_val <= root->val) {
            max_val = root->val;
            ++ans;
        }
        count(root->left, max_val, ans);
        count(root->right, max_val, ans);
    }
};