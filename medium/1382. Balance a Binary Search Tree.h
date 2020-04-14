// 1382. Balance a Binary Search Tree

// Runtime: 176 ms, faster than 68.09% of C++ online submissions for Balance a Binary Search Tree.
// Memory Usage: 34.9 MB, less than 100.00% of C++ online submissions for Balance a Binary Search Tree.

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        arr(root, nodes);
        return tree(nodes, 0, nodes.size());
    }
    
    void arr(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        arr(root->left, nodes);
        nodes.push_back(root);
        arr(root->right, nodes);
        
        root->left = nullptr;
        root->right = nullptr;
    }
    
    TreeNode* tree(vector<TreeNode*>& nodes, int begin, int end) {
        if (begin >= end) return nullptr;
        int mid = begin + (end - begin) / 2;
        auto root = nodes[mid];
        root->left = tree(nodes, begin, mid);
        root->right = tree(nodes, mid + 1, end);
        return root;
    }
};