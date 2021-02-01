// 333. Largest BST Subtree
// https://leetcode.com/problems/largest-bst-subtree/

// Runtime: 12 ms, faster than 83.30% of C++ online submissions for Largest BST Subtree.
// Memory Usage: 21.6 MB, less than 55.30% of C++ online submissions for Largest BST Subtree.
    
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
    
    array<int, 3> post(TreeNode* root) {
        if (!root) 
            return {INT_MAX, INT_MIN, 0};
        
        array<int, 3> l = post(root->left);
        array<int, 3> r = post(root->right);
            
        if (l[1] < root->val && root->val < r[0] && l[2] >= 0 && r[2] >= 0) {
            int cnt = l[2] + 1 + r[2];
            if (ans < cnt) ans = cnt;
            return {min(l[0], root->val), max(r[1], root->val), cnt};
        } else {
            return {-1, -1, -1};
        }
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        ans = 1;
        post(root);
        return ans;
    }
};

// Runtime: 16 ms, faster than 57.81% of C++ online submissions for Largest BST Subtree.
// Memory Usage: 24.9 MB, less than 28.73% of C++ online submissions for Largest BST Subtree.
    
// passed all test cases, but
// WA [100,2,2,2,2,-1,3]
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