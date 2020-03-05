// 515. Find Largest Value in Each Tree Row

// Runtime: 16 ms, faster than 77.42% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 20.2 MB, less than 100.00% of C++ online submissions for Find Largest Value in Each Tree Row.

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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            int val = INT_MIN;
            while (size-- > 0) {
                auto node = q.front();
                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
                
                val = max(val, node->val);
            }
            ans.push_back(val);
        }
        return ans;
    }
};