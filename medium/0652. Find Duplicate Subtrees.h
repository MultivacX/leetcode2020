// 652. Find Duplicate Subtrees

// Runtime: 76 ms, faster than 6.84% of C++ online submissions for Find Duplicate Subtrees.
// Memory Usage: 91.9 MB, less than 33.33% of C++ online submissions for Find Duplicate Subtrees.

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
    unordered_map<string, vector<TreeNode*>> m;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) return {};
        
        vector<TreeNode*> ans;
        f(root);
        for (auto it : m) {
            if (it.second.size() > 1) {
                ans.push_back(it.second.front());
            }
        }
        return ans;
    }
    
    string f(TreeNode* root) {
        if (!root) return "N";
        
        string a(to_string(root->val));
        a += "," + f(root->left);
        a += "," + f(root->right);
        
        if (m.count(a)) {
            m[a].push_back(root);
        } else {
            m.insert({a, {root}});
        }
        
        return a;
    }
};