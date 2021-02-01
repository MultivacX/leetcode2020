// 1602. Find Nearest Right Node in Binary Tree
// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/

// Runtime: 184 ms, faster than 67.17% of C++ online submissions for Find Nearest Right Node in Binary Tree.
// Memory Usage: 88.2 MB, less than 31.10% of C++ online submissions for Find Nearest Right Node in Binary Tree.
    
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == u) return nullptr;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front(); q.pop();
                if (node == u) {
                    if (size == 0) return nullptr;
                    return q.front();
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return nullptr;
    }
};