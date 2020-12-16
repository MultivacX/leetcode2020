// 1676. Lowest Common Ancestor of a Binary Tree IV
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/

// Runtime: 120 ms, faster than 61.69% of C++ online submissions for Lowest Common Ancestor of a Binary Tree IV.
// Memory Usage: 44.4 MB, less than 54.92% of C++ online submissions for Lowest Common Ancestor of a Binary Tree IV.

    
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
    unordered_set<TreeNode*> s;
    
    TreeNode* lca(TreeNode* root) {
        if (!root) return nullptr;
        if (s.count(root)) return root;
        auto l = lca(root->left);
        auto r = lca(root->right);
        if (l && r) return root;
        return l ? l : r;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for (auto node : nodes) s.insert(node);
        return lca(root);
    }
};