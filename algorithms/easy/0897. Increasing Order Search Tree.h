// 897. Increasing Order Search Tree

// Runtime: 4 ms, faster than 77.16% of C++ online submissions for Increasing Order Search Tree.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Increasing Order Search Tree.

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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        vector<TreeNode*> nodes;
        f(root, nodes);
        nodes.push_back(nullptr);
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        return nodes[0];
    }
    
    void f(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        
        f(root->left, nodes);
        nodes.push_back(root);
        f(root->right, nodes);
    }
};