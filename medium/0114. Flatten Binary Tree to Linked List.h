// 114. Flatten Binary Tree to Linked List

// Runtime: 4 ms, faster than 93.75% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 9.7 MB, less than 87.50% of C++ online submissions for Flatten Binary Tree to Linked List.

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
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto n = s.top();
            s.pop();
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
            n->right = n->left ? n->left : (s.empty() ? nullptr : s.top());
            n->left = nullptr;
        }
    }
};