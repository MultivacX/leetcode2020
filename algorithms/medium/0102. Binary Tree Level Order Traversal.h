// 102. Binary Tree Level Order Traversal

// Runtime: 8 ms, faster than 57.52% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 13.9 MB, less than 80.28% of C++ online submissions for Binary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> v;
            for (int i = 0; i < cnt; ++i) {
                const TreeNode* node = q.front();
                v.push_back(node->val);
                
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back({});
            for (int size = q.size(); size > 0; --size) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                ans.back().push_back(node->val);
            }
        }
        return ans;
    }
};