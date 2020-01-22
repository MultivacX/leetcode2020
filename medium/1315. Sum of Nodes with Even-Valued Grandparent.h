// 1315. Sum of Nodes with Even-Valued Grandparent

// Runtime: 76 ms, faster than 5.72% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
// Memory Usage: 31.3 MB, less than 100.00% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.

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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        sum(root, nullptr, nullptr, ans);
        return ans;
    }
    
    void sum(TreeNode* node, TreeNode* p, TreeNode* g, int& ans) {
        if (!node) return;
        if (g && g->val % 2 == 0) ans += node->val;
        sum(node->left, node, p, ans);
        sum(node->right, node, p, ans);
    }
};