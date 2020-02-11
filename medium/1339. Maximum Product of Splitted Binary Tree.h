// 1339. Maximum Product of Splitted Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* class Solution {
public:
    unordered_map<TreeNode*, int64_t> sums;
    int64_t total = 0;
    int ans = 0;
    
    int maxProduct(TreeNode* root) {
        total = sum(root);
        product(root);
        return ans;
    }
    
    int64_t sum(TreeNode* root) {
        if (!root) return 0;
        
        auto it = sums.find(root);
        if (it != sums.end()) return it->second;
        
        int64_t l = sum(root->left);
        int64_t r = sum(root->right);
        sums[root] = l + root->val + r;
        return sums[root];
    }
    
    void product(TreeNode* root) {
        if (!root) return;
        
        int p = (sums[root] % 1000000007) * ((total - sums[root]) % 1000000007) % 1000000007;
        ans = max(ans, p);
        product(root->left);
        product(root->right);
    }
}; */