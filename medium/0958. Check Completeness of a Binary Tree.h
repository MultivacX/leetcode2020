// 958. Check Completeness of a Binary Tree

// Runtime: 4 ms, faster than 86.83% of C++ online submissions for Check Completeness of a Binary Tree.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Check Completeness of a Binary Tree.

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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        bool hasNull = false;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop_front();
                
                if (node->left) {
                    if (hasNull) return false;
                    q.push_back(node->left);
                } else {
                    hasNull = true;
                }
                
                if (node->right) {
                    if (hasNull) return false;
                    q.push_back(node->right);
                } else {
                    hasNull = true;
                }
            }
        }
        return true;
    }
};