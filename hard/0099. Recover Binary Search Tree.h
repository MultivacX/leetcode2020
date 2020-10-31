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

// 1918 / 1918 test cases passed.
// Status: Accepted
// Runtime: 36 ms
// Memory Usage: 58.8 MB
class Solution {
    vector<TreeNode*> nodes;
    vector<int> vals;
    
    TreeNode* pre = nullptr;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        if (pre && pre->val > root->val) {
            nodes.push_back(pre);
            nodes.push_back(root);
            vals.push_back(pre->val);
            vals.push_back(root->val);
        }
        pre = root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        // nodes.size() = [2, 4]
        sort(begin(vals), end(vals));
        for (int i = 0; i < nodes.size(); ++i) 
            nodes[i]->val = vals[i];
    }
};