// 993. Cousins in Binary Tree

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Cousins in Binary Tree.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Cousins in Binary Tree.

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y) return false;
        
        deque<pair<TreeNode*, TreeNode*>> q;
        q.push_back({root, nullptr});
        while (!q.empty()) {
            TreeNode* xnode = nullptr;
            TreeNode* xparent = nullptr;
            TreeNode* ynode = nullptr;
            TreeNode* yparent = nullptr;
            
            int size = q.size();
            while (size--) {
                auto node = q.front().first;
                if (node->val == x) {
                    xnode = node;
                    xparent = q.front().second;
                } else if (node->val == y) {
                    ynode = node;
                    yparent = q.front().second;
                }
                if (xnode && ynode) break;
                q.pop_front();
                if (node->left) q.push_back({node->left, node});
                if (node->right) q.push_back({node->right, node});
            }
            
            if (xnode) return ynode && xparent != yparent;
            if (ynode) return xnode && xparent != yparent;
        }
        return false;
    }
};