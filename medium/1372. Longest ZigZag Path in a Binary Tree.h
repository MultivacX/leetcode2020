// 1372. Longest ZigZag Path in a Binary Tree

// Runtime: 604 ms, faster than 5.02% of C++ online submissions for Longest ZigZag Path in a Binary Tree.
// Memory Usage: 135.3 MB, less than 100.00% of C++ online submissions for Longest ZigZag Path in a Binary Tree.

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
    enum {
        L = 1,
        R = 2,
    };
    unordered_map<TreeNode*, int> ml;
    unordered_map<TreeNode*, int> mr;
    int ans = 0;
    
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        z(root, L);
        z(root, R);
        longestZigZag(root->left);
        longestZigZag(root->right);
        return ans;
    }
    
    int z(TreeNode* root, int flag) {
        if (!root) return 0;
        
        if (flag == L) {
            if (!ml.count(root)) 
                ml[root] = root->left ? 1 + z(root->left, R) : 0;
            ans = max(ans, ml[root]);
            return ml[root];
        } else {
            if (!mr.count(root)) 
                mr[root] = root->right ? 1 + z(root->right, L) : 0;
            ans = max(ans, mr[root]);
            return mr[root];
        }
    }
};