// 142. Linked List Cycle II

// Runtime: 12 ms, faster than 77.06% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 9.8 MB, less than 78.57% of C++ online submissions for Linked List Cycle II.

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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
            if (slow == fast)
                break;
        }
        if (!fast)
            return fast;
        
        auto p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};