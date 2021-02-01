// 1609. Even Odd Tree
// https://leetcode.com/problems/even-odd-tree/

// Runtime: 348 ms, faster than 97.00% of C++ online submissions for Even Odd Tree.
// Memory Usage: 152.7 MB, less than 71.93% of C++ online submissions for Even Odd Tree.

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
    bool isRightNode(TreeNode* node, int lv, int& pre) {
        // cout << pre << " " << node->val << ", lv:" << lv << " " << (node->val & 1) << " " << (lv & 1) << endl;
        
        if ((node->val & 1) == (lv & 1)) return false;
        
        if (pre < 0) {
            pre = node->val;
            return true;
        } else if (lv & 1) {
            bool ans = pre > node->val;
            pre = node->val;
            return ans;
        } else {
            bool ans = pre < node->val;
            pre = node->val;
            return ans;
        }
    }
    
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lv = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0, pre = -1; i < size; ++i) {
                auto node = q.front();
                q.pop();
                
                if (!isRightNode(node, lv, pre)) return false;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++lv;
        }
        return true;
    }
};