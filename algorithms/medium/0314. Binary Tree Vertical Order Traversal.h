// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

// Runtime: 4 ms, faster than 89.45% of C++ online submissions for Binary Tree Vertical Order Traversal.
// Memory Usage: 12.7 MB, less than 39.24% of C++ online submissions for Binary Tree Vertical Order Traversal.
    
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        
        unordered_map<int, vector<int>> m;
        int minCol = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front().first;
                auto col = q.front().second;
                m[col].push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push({node->left, col - 1});
                    if (minCol > col - 1) minCol = col - 1;
                }
                if (node->right) q.push({node->right, col + 1});
            }
        }
        
        vector<vector<int>> ans;
        while (m.count(minCol))
            ans.push_back(m[minCol++]);
        return ans;
    }
};