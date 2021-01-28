// 1740. Find Distance in a Binary Tree
// https://leetcode.com/problems/find-distance-in-a-binary-tree/

// Runtime: 40 ms, faster than 100.00% of C++ online submissions for Find Distance in a Binary Tree.
// Memory Usage: 32.4 MB, less than 100.00% of C++ online submissions for Find Distance in a Binary Tree.
    
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
    bool getPath(TreeNode* root, int target, vector<int>& path) {
        if (!root) return false;
        
        if (root->val == target) return true;
        
        path.push_back(root->val);
        if (getPath(root->left, target, path))
            return true;
        if (getPath(root->right, target, path))
            return true;
        path.pop_back();
        
        return false;
    }
    
public:
    int findDistance(TreeNode* root, int p, int q) {
        vector<int> path_p, path_q;
        getPath(root, p, path_p); path_p.push_back(p);
        getPath(root, q, path_q); path_q.push_back(q);
        // for (auto v : path_p) cout << v << " -> "; cout << endl;
        // for (auto v : path_q) cout << v << " -> "; cout<< endl << endl;
        
        int i = 0;
        while (i < min(path_p.size(), path_q.size()) && path_p[i] == path_q[i]) 
            ++i;
        return path_p.size() + path_q.size() - i * 2;
    }
};