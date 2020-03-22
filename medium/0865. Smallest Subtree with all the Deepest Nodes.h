// 865. Smallest Subtree with all the Deepest Nodes

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.
// Memory Usage: 13.5 MB, less than 100.00% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        
        vector<TreeNode*> parents(500, nullptr);
        vector<TreeNode*> cur_level{root};
        while (!cur_level.empty()) {
            vector<TreeNode*> next_level;
            for (auto node : cur_level) {
                if (node->left) {
                    parents[node->left->val] = node;
                    next_level.push_back(node->left);
                }
                if (node->right) {
                    parents[node->right->val] = node;
                    next_level.push_back(node->right);
                }
            }
            
            if (next_level.empty()) {
                if (cur_level.size() == 1) return cur_level.front();
                
                unordered_set<TreeNode*> s;
                for (auto node : cur_level) 
                    s.insert(parents[node->val]);
                while (s.size() > 1) {
                    unordered_set<TreeNode*> t;
                    for (auto node : s)
                        t.insert(parents[node->val]);
                    swap(s, t);
                }
                return *s.begin() == nullptr ? root : *s.begin();
            }
            
            swap(cur_level, next_level);
        }
        
        return root;
    }
};