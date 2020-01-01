// 99. Recover Binary Search Tree

// Runtime: 16 ms, faster than 97.20% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 18.7 MB, less than 42.10% of C++ online submissions for Recover Binary Search Tree.

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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        vector<int> vals(nodes.size(), 0);
        for (int i = 0; i < nodes.size(); ++i) vals[i] = nodes[i]->val;
        sort(vals.begin(), vals.end());
        for (int i = 0; i < nodes.size(); ++i) nodes[i]->val = vals[i];
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
};