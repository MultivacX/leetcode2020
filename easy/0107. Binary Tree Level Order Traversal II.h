// 107. Binary Tree Level Order Traversal II

// Runtime: 4 ms, faster than 94.93% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 13.9 MB, less than 64.86% of C++ online submissions for Binary Tree Level Order Traversal II.

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> layer{root};
        while (!layer.empty()) {
            vector<int> vals;
            vector<TreeNode*> tmp;
            for (auto node : layer) {
                vals.push_back(node->val);
                if (node->left) tmp.push_back(node->left);
                if (node->right) tmp.push_back(node->right);
            }
            ans.push_back(vals);
            swap(layer, tmp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};