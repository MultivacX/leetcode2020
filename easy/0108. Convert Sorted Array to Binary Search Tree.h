// 108. Convert Sorted Array to Binary Search Tree

// Runtime: 24 ms, faster than 80.62% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 23.5 MB, less than 24.32% of C++ online submissions for Convert Sorted Array to Binary Search Tree.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size());
    }
    
    TreeNode* bst(const vector<int>& nums, int begin, int end) {
        if (begin >= end) return nullptr;
        
        int mid = begin + (end - begin) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = bst(nums, begin, mid);
        root->right = bst(nums, mid + 1, end);
        return root;
    }
};