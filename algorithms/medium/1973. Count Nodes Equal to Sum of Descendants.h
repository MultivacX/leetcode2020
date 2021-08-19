// 1973. Count Nodes Equal to Sum of Descendants
// https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/

// Runtime: 328 ms, faster than 100.00% of C++ online submissions for Count Nodes Equal to Sum of Descendants.
// Memory Usage: 200.1 MB, less than 100.00% of C++ online submissions for Count Nodes Equal to Sum of Descendants.
    
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int k = 0;
    
    int64_t sumOfDescendants(TreeNode* root) {
        if (!root) return 0;
        
        int64_t l = sumOfDescendants(root->left);
        int64_t r = sumOfDescendants(root->right);
        
        if (l - root->val + r == 0) ++k;
        
        return l + r + root->val;
    }
    
public:
    int equalToDescendants(TreeNode* root) {
        sumOfDescendants(root);
        return k;
    }
};