// 1022. Sum of Root To Leaf Binary Numbers

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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        sum(root, 0, ans);
        return ans;
    }
    
    void sum(TreeNode* root, int val, int& ans) {
        if (!root) return;
        
        val = (val << 1) + root->val;
        if (!root->left && !root->right) {
            ans += val;
            // cout << bitset<32>(val) << endl;
        } else {
            sum(root->left, val, ans);
            sum(root->right, val, ans);   
        }
    }
};