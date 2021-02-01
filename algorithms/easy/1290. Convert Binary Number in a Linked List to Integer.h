// 1290. Convert Binary Number in a Linked List to Integer

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};