// 938. Range Sum of BST

// Runtime: 164 ms, faster than 17.31% of C++ online submissions for Range Sum of BST.
// Memory Usage: 38.8 MB, less than 100.00% of C++ online submissions for Range Sum of BST.

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int ans = root->val >= L && root->val <= R ? root->val : 0;
        if (root->val <= L) ans += rangeSumBST(root->right, L, R);
        else if (root->val >= R) ans += rangeSumBST(root->left, L, R);
        else ans += rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        return ans;
    }
};

// Runtime: 164 ms, faster than 17.31% of C++ online submissions for Range Sum of BST.
// Memory Usage: 38.6 MB, less than 100.00% of C++ online submissions for Range Sum of BST.
/* class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        return (root->val >= L && root->val <= R ? root->val : 0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}; */