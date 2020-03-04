// 508. Most Frequent Subtree Sum

// Runtime: 24 ms, faster than 59.58% of C++ online submissions for Most Frequent Subtree Sum.
// Memory Usage: 22.5 MB, less than 100.00% of C++ online submissions for Most Frequent Subtree Sum.

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        
        unordered_map<int, int> m;
        sum(root, m);
        int frequent = 0;
        for (auto it : m) 
            frequent = max(frequent, it.second);
        vector<int> sums;
        for (auto it : m) 
            if (frequent == it.second)
                sums.push_back(it.first);
        return sums;
    }
    
    int sum(TreeNode* root, unordered_map<int, int>& m) {
        if (!root) 
            return 0;
        
        int s = sum(root->left, m) + root->val + sum(root->right, m);
        ++m[s];
        return s;
    }
};