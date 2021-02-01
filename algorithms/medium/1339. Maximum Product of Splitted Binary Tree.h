// 1339. Maximum Product of Splitted Binary Tree

// Runtime: 208 ms, faster than 35.69% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// Memory Usage: 88.4 MB, less than 100.00% of C++ online submissions for Maximum Product of Splitted Binary Tree.

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
    unordered_set<int64_t> sums;
    
    int maxProduct(TreeNode* root) {
        int64_t total = sum(root);
        int64_t ans = 0;
        for (int64_t s : sums) ans = max(ans, s * (total - s));
        return ans % 1000000007;
    }
    
    int64_t sum(TreeNode* root) {
        return !root ? 0 : *sums.insert(sum(root->left) + root->val + sum(root->right)).first;
    }
};

/* class Solution {
public:
    unordered_map<TreeNode*, int64_t> sums;
    int64_t total = 0;
    int64_t ans = 0;
    
    int64_t maxProduct(TreeNode* root) {
        total = sum(root);
        product(root);
        return ans % 1000000007;
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
        
        int64_t p = (sums[root]) * (total - sums[root]);
        ans = max(ans, p);
        product(root->left);
        product(root->right);
    }
}; */