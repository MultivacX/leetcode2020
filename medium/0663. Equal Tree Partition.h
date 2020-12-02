// 663. Equal Tree Partition
// https://leetcode.com/problems/equal-tree-partition/

// Runtime: 52 ms, faster than 44.05% of C++ online submissions for Equal Tree Partition.
// Memory Usage: 39.4 MB, less than 15.48% of C++ online submissions for Equal Tree Partition.
    
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
    unordered_set<int> subsums;
    
    int sum(TreeNode* root) {
        if (!root) return 0;
        
        int l = sum(root->left);
        if (root->left) subsums.insert(l);
        int r = sum(root->right);
        if (root->right) subsums.insert(r);
        
        return l + root->val + r;
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        int s = sum(root);
        // for (auto i : subsums) cout << i << " ";
        for (auto i : subsums) 
            if (i * 2 == s) return true;
        return false;
    }
};