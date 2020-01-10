// 988. Smallest String Starting From Leaf

// Runtime: 8 ms, faster than 94.09% of C++ online submissions for Smallest String Starting From Leaf.
// Memory Usage: 19.6 MB, less than 91.30% of C++ online submissions for Smallest String Starting From Leaf.

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
    string ans;
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return ans;
        f(root, string(1, 'a' + root->val));
        return ans;
    }
    
    void f(TreeNode* root, string s) {
        if (root->left) f(root->left, string(1, 'a' + root->left->val) + s);
        if (root->right) f(root->right, string(1, 'a' + root->right->val) + s);
        if (!root->left && !root->right) {
            if (ans.empty()) ans = s;
            else if (ans > s) ans = s;
        }
    }
};