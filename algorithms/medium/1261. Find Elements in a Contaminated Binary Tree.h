// 1261. Find Elements in a Contaminated Binary Tree

// Runtime: 44 ms, faster than 59.59% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
// Memory Usage: 30 MB, less than 100.00% of C++ online submissions for Find Elements in a Contaminated Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root)
    : _root(root) {
        recover(_root, nullptr);
    }
    
    bool find(int target) {
        return _vals.count(target);
    }
    
    void recover(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        if (!parent) node->val = 0;
        else if (node == parent->left) node->val = 2 * parent->val + 1;
        else node->val = 2 * parent->val + 2;
        
        _vals.insert(node->val);
        
        recover(node->left, node);
        recover(node->right, node);
    }
    
    TreeNode* _root;
    unordered_set<int> _vals;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */