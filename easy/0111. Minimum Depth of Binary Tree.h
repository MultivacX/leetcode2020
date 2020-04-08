// 111. Minimum Depth of Binary Tree

// Runtime: 12 ms, faster than 74.96% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 17.2 MB, less than 100.00% of C++ online submissions for Minimum Depth of Binary Tree.

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int d = 1;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop_front();
                if (!node->left && !node->right) return d;
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            ++d;
        }
        return d;
    }
};