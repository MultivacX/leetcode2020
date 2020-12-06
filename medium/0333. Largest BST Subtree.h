// 333. Largest BST Subtree
// Runtime: 16 ms, faster than 57.81% of C++ online submissions for Largest BST Subtree.
// Memory Usage: 24.9 MB, less than 28.73% of C++ online submissions for Largest BST Subtree.
    
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
    int ans = 0;
    unordered_set<int> visited;
    
    array<int, 3> post(TreeNode* root) {
        if (!root->left && !root->right) {
            visited.insert(root->val);
            return {root->val, root->val, 1};
        }
        
        array<int, 3> l, r;
        if (root->left) l = post(root->left);
        if (root->right) r = post(root->right);
            
        if (!visited.insert(root->val).second)
            return {0, 0, -1};
        
        int cmin = root->val;
        int cmax = root->val;
        int ccnt = 1;
        
        if (root->left) {
            if (l[1] >= root->val || l[2] < 0)
                return {0, 0, -1};
            cmin = l[0];
            ccnt += l[2];
        } 
        
        if (root->right) {
            if (r[0] <= root->val || r[2] < 0)
                return {0, 0, -1};
            cmax = r[1];
            ccnt += r[2];
        }
        
        ans = max(ans, ccnt);
        return {cmin, cmax, ccnt};
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        ans = 1;
        post(root);
        return ans;
    }
};