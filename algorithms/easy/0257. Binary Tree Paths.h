// 257. Binary Tree Paths

// Runtime: 4 ms, faster than 73.15% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Binary Tree Paths.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        go(root);
        return ans;
    }
    
    vector<string> ans;
    vector<int> v;
    
    void go(TreeNode* root) {
        if (!root) return;
        
        v.push_back(root->val);
        go(root->left);
        go(root->right);
        if (!root->left && !root->right) {
            // for (int i : v) cout << i << ",";
            // cout << endl;
            string s;
            for (int i = 0; i < v.size(); ++i) {
                s += to_string(v[i]);
                if (i + 1 < v.size())
                    s += "->";
            }
            ans.push_back(s);
        }
        v.pop_back();
    }
};