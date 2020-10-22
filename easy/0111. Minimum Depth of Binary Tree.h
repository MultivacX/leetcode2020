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

// Runtime: 336 ms
// Memory Usage: 144.4 MB
class Solution {
    int ans = INT_MAX;
    
    void minDepth(TreeNode* root, int d) {
        if (!root) return;
        ++d;
        if (ans < d) return;
        if (!root->left && !root->right) {
            ans = min(ans, d);
            return;
        }
        minDepth(root->left, d);
        minDepth(root->right, d);
    }
    
public:
    int minDepth(TreeNode* root) {
        minDepth(root, 0);
        return ans == INT_MAX ? 0 : ans;
    }
};