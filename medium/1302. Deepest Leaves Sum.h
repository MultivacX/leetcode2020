// 1302. Deepest Leaves Sum

// Runtime: 48 ms, faster than 73.18% of C++ online submissions for Deepest Leaves Sum.
// Memory Usage: 32 MB, less than 100.00% of C++ online submissions for Deepest Leaves Sum.

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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            int tmp = 0;
            while (size > 0) {
                --size;
                
                auto node = q.front();
                q.pop_front();
                
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
                
                tmp += node->val;
            }
            ans = tmp;
        }
        return ans;
    }
};