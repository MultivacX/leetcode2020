// 199. Binary Tree Right Side View

// Runtime: 4 ms, faster than 74.78% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 9.6 MB, less than 75.68% of C++ online submissions for Binary Tree Right Side View.

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            ans.push_back(q.back()->val);
            
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop_front();
                if (p->left) q.push_back(p->left);
                if (p->right) q.push_back(p->right);
            }
        }
        return ans;
    }
};