// 366. Find Leaves of Binary Tree
// https://leetcode.com/problems/find-leaves-of-binary-tree/

// Runtime: 4 ms, faster than 53.22% of C++ online submissions for Find Leaves of Binary Tree.
// Memory Usage: 8.6 MB, less than 98.00% of C++ online submissions for Find Leaves of Binary Tree.
    
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        
        // {child, parent}
        unordered_map<TreeNode*, TreeNode*> nodes;
        nodes.insert({root, nullptr});
        queue<TreeNode*> q, leaves;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front(); q.pop();
                if (node->left) {
                    nodes.insert({node->left, node});
                    q.push(node->left);
                }
                if (node->right) {
                    nodes.insert({node->right, node});
                    q.push(node->right);
                }
                if (!node->left && !node->right)
                    leaves.push(node);
            }
        }
        
        vector<vector<int>> ans;
        while (!leaves.empty()) {
            int size = leaves.size();
            ans.push_back({});
            while (size-- > 0) {
                auto node = leaves.front(); leaves.pop();
                auto p = nodes[node]; nodes.erase(node);
                if (p && p->left == node) p->left = nullptr;
                if (p && p->right == node) p->right = nullptr;
                if (p && !p->left && !p->right)
                    leaves.push(p);
                ans.back().push_back(node->val);
            }
        }
        return ans;
    }
};