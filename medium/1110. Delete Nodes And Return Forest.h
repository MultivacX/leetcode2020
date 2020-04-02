// 1110. Delete Nodes And Return Forest

// Runtime: 32 ms, faster than 65.59% of C++ online submissions for Delete Nodes And Return Forest.
// Memory Usage: 20.5 MB, less than 100.00% of C++ online submissions for Delete Nodes And Return Forest.

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> _to_delete(begin(to_delete), end(to_delete));
        f(nullptr, root, _to_delete, forest);
        return forest;
    }
    
    void f(TreeNode* parent, TreeNode* node, unordered_set<int>& to_delete, vector<TreeNode*>& forest) {
        if (!node) return;
        
        auto l = node->left;
        auto r = node->right;
        
        if (to_delete.count(node->val)) {
            to_delete.erase(node->val); 
            if (parent) {
                if (node == parent->left) parent->left = nullptr;
                else parent->right = nullptr;
            }
            node->left = nullptr;
            node->right = nullptr;
            // delete node;
            node = nullptr;
        } else {
            if (!parent) forest.push_back(node);
            if (to_delete.empty()) return;
        }
        
        f(node, l, to_delete, forest);
        f(node, r, to_delete, forest);
    }
};