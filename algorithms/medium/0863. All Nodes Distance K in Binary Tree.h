// 863. All Nodes Distance K in Binary Tree

// Runtime: 4 ms, faster than 93.95% of C++ online submissions for All Nodes Distance K in Binary Tree.
// Memory Usage: 15.9 MB, less than 54.55% of C++ online submissions for All Nodes Distance K in Binary Tree.

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        
        vector<int> ans;
        distanceDownFromTarget(target, K, ans);
        
        unordered_map<TreeNode*, TreeNode*> parents;
        findTarget(root, target, parents);
        if (parents.count(target)) {
            unordered_set<TreeNode*> visited;
            visited.insert(target);
            distanceUpFromTarget(parents[target], K - 1, parents, visited, ans);
        }
        
        return ans;
    }
    
    bool findTarget(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root == target) return true;
        if (root->left) {
            parents[root->left] = root;
            if (findTarget(root->left, target, parents)) return true;
        }
        if (root->right) {
            parents[root->right] = root;
            if (findTarget(root->right, target, parents)) return true;
        }
        return false;
    }
    
    void distanceDownFromTarget(TreeNode* root, int K, vector<int>& ans) {
        if (!root) return;
        if (K == 0) {
            ans.push_back(root->val);
            return;
        }
        distanceDownFromTarget(root->left, K - 1, ans);
        distanceDownFromTarget(root->right, K - 1, ans);
    }
    
    void distanceUpFromTarget(TreeNode* root, int K, unordered_map<TreeNode*, TreeNode*>& parents, unordered_set<TreeNode*>& visited, vector<int>& ans) {
        if (!root || visited.count(root)) return;
        if (K == 0) {
            ans.push_back(root->val);
            return;
        }
        visited.insert(root);
        if (parents.count(root))
            distanceUpFromTarget(parents[root], K - 1, parents, visited, ans);
        distanceUpFromTarget(root->left, K - 1, parents, visited, ans);
        distanceUpFromTarget(root->right, K - 1, parents, visited, ans);
    }
};