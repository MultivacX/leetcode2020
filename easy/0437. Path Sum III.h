// 437. Path Sum III

// Runtime: 20 ms, faster than 76.16% of C++ online submissions for Path Sum III.
// Memory Usage: 15.3 MB, less than 25.81% of C++ online submissions for Path Sum III.

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
    int pathSum(TreeNode* root, int sum) {
        _sum = sum;
        go(root, 0);
        return ans;
    }
    
    int ans = 0;
    unordered_map<int, int> prefix_sums{{0, 1}};
    int _sum;
    
    void go(TreeNode* root, int prefix_sum) {
        if (!root) return;
        
        int cur = prefix_sum + root->val;
        if (prefix_sums.count(cur - _sum)) ans += prefix_sums[cur - _sum];
        ++prefix_sums[cur];
        go(root->left, cur);
        go(root->right, cur);
        --prefix_sums[cur];
    }
};