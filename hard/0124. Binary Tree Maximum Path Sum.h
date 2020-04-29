// 124. Binary Tree Maximum Path Sum

// Runtime: 88 ms, faster than 5.01% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 39.3 MB, less than 6.06% of C++ online submissions for Binary Tree Maximum Path Sum.

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
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        f(root);
        return ans;
    }
    
    int ans;
    map<TreeNode*, int> m;
    void f(TreeNode* root) {
        if (!root || m.find(root) != m.end()) return;
        
        if (!root->left && !root->right) {
            m[root] = root->val;
            ans = max(ans, m[root]);
            return;
        }
        
        f(root->left);
        f(root->right);
        
        int l = root->left ? m[root->left] : 0;
        int r = root->right ? m[root->right] : 0;
        
        m[root] = root->val + max(0, max(l, r));
        
        int v = root->val + max(0, l) + max(0, r);
        ans = max(ans, v);
    }
};

// Runtime: 36 ms, faster than 33.76% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 28.8 MB, less than 6.06% of C++ online submissions for Binary Tree Maximum Path Sum.
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        ans = INT_MIN;
        sum(root);
        return ans;
    }
    
    int ans;
    int sum(TreeNode* root) {
        if (!root) return 0;
        int l = sum(root->left);
        int r = sum(root->right);
        int x = root->val + max(0, max(l, r));
        // cout << l << ", " << x << ", " << r << endl;
        ans = max(max(ans, x), root->val + l + r);
        return x;
    }
};