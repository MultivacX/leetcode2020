// 1161. Maximum Level Sum of a Binary Tree

// Runtime: 292 ms, faster than 20.33% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// Memory Usage: 104.7 MB, less than 100.00% of C++ online submissions for Maximum Level Sum of a Binary Tree.

// Time Complexity: O(nodes).
// Space Complexity: O(levels).

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
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        get_sum(root, sums, 0);
        return max_element(begin(sums), end(sums)) - begin(sums) + 1;
    }
    
    void get_sum(TreeNode* root, vector<int>& sums, int level) {
        if (!root) return;
        
        if (sums.size() == level) sums.emplace_back(0);
        sums[level] += root->val;
        get_sum(root->left, sums, level + 1);
        get_sum(root->right, sums, level + 1);
    }
};