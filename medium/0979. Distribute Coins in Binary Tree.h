// 979. Distribute Coins in Binary Tree

// Runtime: 12 ms, faster than 51.14% of C++ online submissions for Distribute Coins in Binary Tree.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Distribute Coins in Binary Tree.

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
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        
        vector<vector<TreeNode*>> levels;
        unordered_map<TreeNode*, TreeNode*> parents;
        
        vector<TreeNode*> v{root};
        while (!v.empty()) {
            levels.push_back(v);
            
            vector<TreeNode*> t;
            for (auto node : v) {
                if (node->left) {
                    t.push_back(node->left);
                    parents[node->left] = node;
                }
                if (node->right) {
                    t.push_back(node->right);
                    parents[node->right] = node;
                }
            }
            swap(v, t);
        }
        
        int moves = 0;
        for (int i = levels.size() - 1; i >= 0; --i) {
            for (auto node : levels[i]) {
                if (node->val == 1) continue;
                if (parents.count(node)) {
                    parents[node]->val += node->val - 1;
                    moves += abs(node->val - 1);
                }
            }
        }
        return moves;
    }
};