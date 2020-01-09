// 113. Path Sum II

// Runtime: 20 ms, faster than 44.66% of C++ online submissions for Path Sum II.
// Memory Usage: 37.9 MB, less than 7.89% of C++ online submissions for Path Sum II.

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        f(root, sum, ans, {});
        return ans;
    }
    
    void f(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int> path) {
        if (!root) return;
        path.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        f(root->left, sum - root->val, ans, path);
        f(root->right, sum - root->val, ans, path);
    }
};