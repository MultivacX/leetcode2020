// 145. Binary Tree Postorder Traversal

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.3 MB, less than 67.74% of C++ online submissions for Binary Tree Postorder Traversal.

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
    /*vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> s;
        s.push(root);
        auto curr = root;
        while (!s.empty() || curr) {
            
        }
    }*/
    
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        f(root, ans);
        return ans;
    }
    
    void f(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        f(root->left, ans);
        f(root->right, ans);
        ans.push_back(root->val);
    }
};