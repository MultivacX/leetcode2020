// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

// Runtime: 720 ms, faster than 25.44% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
// Memory Usage: 164.3 MB, less than 100.00% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) return nullptr;
        if (original == target) return cloned;
        auto node = getTargetCopy(original->left, cloned->left, target);
        if (!node) node = getTargetCopy(original->right, cloned->right, target);
        return node;
    }
};