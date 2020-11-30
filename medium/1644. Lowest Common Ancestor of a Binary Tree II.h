// 1644. Lowest Common Ancestor of a Binary Tree II
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

// Runtime: 144 ms, faster than 69.79% of C++ online submissions for Lowest Common Ancestor of a Binary Tree II.
// Memory Usage: 65.9 MB, less than 21.31% of C++ online submissions for Lowest Common Ancestor of a Binary Tree II.
    
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
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    
    void find(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& path) {
        if (!root) return;
        
        path.push_back(root);
        if (root == p) pathP = path;
        if (root == q) pathQ = path;
        
        if (pathP.empty() || pathP.back() != p || pathQ.empty() || pathQ.back() != q) {
            find(root->left, p, q, path);
            find(root->right, p, q, path);
            path.pop_back();
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        find(root, p, q, path);
        TreeNode* lca = nullptr;
        if (!pathP.empty() && !pathQ.empty()) 
            for (int i = 0; i < min(pathP.size(), pathQ.size()) && pathP[i] == pathQ[i]; ++i)
                lca = pathP[i];
        return lca;
    }
};