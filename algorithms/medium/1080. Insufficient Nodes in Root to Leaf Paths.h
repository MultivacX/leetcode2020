// 1080. Insufficient Nodes in Root to Leaf Paths

// Runtime: 52 ms, faster than 91.72% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.
// Memory Usage: 28.2 MB, less than 100.00% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.

// Time Complexity: O(nodes).
// Space Complexity: O(height of tree).

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = f(root, limit, root->val);
        return sum < limit ? nullptr : root;
    }
    
    int f(TreeNode* root, int limit, int sum) {
        bool no_l = !root->left;
        bool no_r = !root->right;
        int l = no_l ? sum : f(root->left, limit, sum + root->left->val);
        int r = no_r ? sum : f(root->right, limit, sum + root->right->val);
        
        // printf("%d -> L:%d, R:%d\n", root->val, l, r);
        // if (no_l) cout << "    R:" << r << endl;
        // if (no_r) cout << "    L:" << l << endl;
        
        if (l < limit) root->left = nullptr;
        if (r < limit) root->right = nullptr;
        if (no_l) return r;
        if (no_r) return l;
        return max(l, r);
    }
};