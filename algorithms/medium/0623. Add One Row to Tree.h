// 623. Add One Row to Tree

// Runtime: 24 ms, faster than 75.16% of C++ online submissions for Add One Row to Tree.
// Memory Usage: 25 MB, less than 20.00% of C++ online submissions for Add One Row to Tree.

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            auto node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        deque<TreeNode*> q;
        q.push_back(root);
        int cur_d = 1;
        while (!q.empty()) {
            int size = q.size();
            if (cur_d + 1 == d) {
                while (size-- > 0) {
                    auto parent = q.front();
                    q.pop_front();
                    
                    auto l = new TreeNode(v);
                    l->left = parent->left;
                    parent->left = l;
                    
                    auto r = new TreeNode(v);
                    r->right = parent->right;
                    parent->right = r;
                }
            } else {
                while (size-- > 0) {
                    auto parent = q.front();
                    q.pop_front();
                    if (parent->left) q.push_back(parent->left);
                    if (parent->right) q.push_back(parent->right);
                }
            }
            ++cur_d;
        }
        return root;
    }
};