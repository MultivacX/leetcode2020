// 1123. Lowest Common Ancestor of Deepest Leaves

// Runtime: 20 ms, faster than 46.70% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
// Memory Usage: 20.7 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth = get_depth(root);
        get_leaves(nullptr, root, 0);
        while (nodes.size() > 1) {
            unordered_set<TreeNode*> tmp;
            for (auto node : nodes) {
                tmp.insert(parents[node]);
            }
            swap(nodes, tmp);
        }
        return *nodes.begin();
    }
    
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> nodes;
    int depth;
    
    int get_depth(TreeNode* root) {
        if (!root) return 0;
        return (root->left || root->right ? 1 : 0) + max(get_depth(root->left), get_depth(root->right));
    }
    
    void get_leaves(TreeNode* parent, TreeNode* node, int d) {
        if (!node || d > depth) return;
        
        parents[node] = parent;
        if (d == depth) {
            nodes.insert(node);
        } else {
            get_leaves(node, node->left, d + 1);
            get_leaves(node, node->right, d + 1);
        }
    }
};