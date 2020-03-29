// 1367. Linked List in Binary Tree

// Runtime: 36 ms, faster than 80.80% of C++ online submissions for Linked List in Binary Tree.
// Memory Usage: 22.5 MB, less than 100.00% of C++ online submissions for Linked List in Binary Tree.

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (f(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool f(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        
        if (head->val != root->val) return false;
        return f(head->next, root->left) || f(head->next, root->right);
    }
};