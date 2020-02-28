// 637. Average of Levels in Binary Tree

// Runtime: 20 ms, faster than 72.40% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 20.6 MB, less than 100.00% of C++ online submissions for Average of Levels in Binary Tree.

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            double v = 0;
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop_front();
                v += node->val;
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            ans.push_back(v / size);
        }
        return ans;
    }
};