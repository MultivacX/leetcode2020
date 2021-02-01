// 572. Subtree of Another Tree

// Runtime: 36 ms, faster than 26.34% of C++ online submissions for Subtree of Another Tree.
// Memory Usage: 21.6 MB, less than 25.00% of C++ online submissions for Subtree of Another Tree.

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        if (!s) return false;
        
        ostringstream s_data;
        serialize(s, s_data);
        ostringstream t_data;
        serialize(t, t_data);
        // cout << s_data.str() << endl;
        // cout << t_data.str() << endl;
        return s_data.str().find(t_data.str()) != string::npos;
    }
    
    void serialize(TreeNode* root, ostringstream& data) {
        data << "[" << root->val << "]";
        if (root->left) serialize(root->left, data);
        else data << "[#]";
        if (root->right) serialize(root->right, data);
        else data << "[#]";
    }
};