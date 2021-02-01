// 742. Closest Leaf in a Binary Tree
// https://leetcode.com/problems/closest-leaf-in-a-binary-tree/

// Runtime: 12 ms, faster than 92.86% of C++ online submissions for Closest Leaf in a Binary Tree.
// Memory Usage: 19.3 MB, less than 87.14% of C++ online submissions for Closest Leaf in a Binary Tree.
    
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
    bool findK(TreeNode* root, int k, vector<TreeNode*>& path2k) {
        if (!root) return false;
        
        path2k.push_back(root);
        if (root->val == k) return true;
        
        if (findK(root->left, k, path2k)) return true;
        if (findK(root->right, k, path2k)) return true;
        
        path2k.pop_back();
        return false;
    }
    
    int ans = -1;
    int distance = INT_MAX;
    
    void findLeaf(TreeNode* root, int d) {
        if (!root || d >= distance) return;
        
        if (!root->left && !root->right) {
            distance = d;
            ans = root->val;
            return;
        }
        
        findLeaf(root->left, d + 1);
        findLeaf(root->right, d + 1);
    }
    
public:
    int findClosestLeaf(TreeNode* root, int k) {
        vector<TreeNode*> path2k;
        findK(root, k, path2k);
        const int N = path2k.size();
        for (int i = N - 1; i >= 0; --i) {
            if (i + 1 == N) {
                findLeaf(path2k[i], 0);
            } else if (path2k[i]->left == path2k[i + 1]) {
                findLeaf(path2k[i]->right, N - i);
            } else {
                findLeaf(path2k[i]->left, N - i);
            }
        }
        return ans;
    }
};