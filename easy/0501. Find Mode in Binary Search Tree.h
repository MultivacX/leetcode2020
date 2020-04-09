// 501. Find Mode in Binary Search Tree

// Runtime: 24 ms, faster than 69.14% of C++ online submissions for Find Mode in Binary Search Tree.
// Memory Usage: 20.7 MB, less than 100.00% of C++ online submissions for Find Mode in Binary Search Tree.

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
    vector<int> findMode(TreeNode* root) {
        count(root);
        pre_cnt = 0;
        find(root);
        return ans;
    }
    
    vector<int> ans;
    int pre_val = 0;
    int pre_cnt = 0;
    int max_cnt = 0;
    
    void count(TreeNode* root) {
        if (!root) return;
        
        count(root->left);
        if (pre_cnt == 0 || pre_val != root->val) {
            pre_val = root->val;
            pre_cnt = 1;
        } else {
            ++pre_cnt;
        }
        max_cnt = max(max_cnt, pre_cnt);
        count(root->right);
    }
    
    void find(TreeNode* root) {
        if (!root) return;
        
        find(root->left);
        if (pre_cnt == 0 || pre_val != root->val) {
            pre_val = root->val;
            pre_cnt = 1;
        } else {
            ++pre_cnt;
        }
        if (pre_cnt == max_cnt) ans.push_back(pre_val);
        find(root->right);
    }
};