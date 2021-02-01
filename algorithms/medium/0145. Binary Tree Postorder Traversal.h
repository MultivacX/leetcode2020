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

// Runtime: 4 ms, faster than 44.47% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.4 MB, less than 78.38% of C++ online submissions for Binary Tree Postorder Traversal.
// iteratively
/*class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};*/