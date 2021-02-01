// 109. Convert Sorted List to Binary Search Tree

// Runtime: 32 ms, faster than 49.08% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 24.5 MB, less than 77.27% of C++ online submissions for Convert Sorted List to Binary Search Tree.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        auto node = head;
        while (node) {
            ++size;
            node = node->next;
        }
        return sortedListToBST(head, size);
    }
    
    TreeNode* sortedListToBST(ListNode* head, int size) {
        if (!head || size <= 0) return nullptr;
        if (size == 1) return new TreeNode(head->val);
        int left_size = size / 2;
        int right_size = size - left_size - 1;
        int cnt = left_size;
        auto node = head;
        while (cnt) {
            --cnt;
            node = node->next;
        }
        auto root = new TreeNode(node->val);
        root->left = sortedListToBST(head, left_size);
        root->right = sortedListToBST(node->next, right_size);
        return root;
    }
};