// 141. Linked List Cycle

// Runtime: 12 ms, faster than 77.19% of C++ online submissions for Linked List Cycle.
// Memory Usage: 9.8 MB, less than 63.16% of C++ online submissions for Linked List Cycle.

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
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head ? head->next : head;
        while (slow && fast) {
            if (slow == fast)
                return true;
            
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        return false;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        auto s = head, f = head;
        while (s && f) {
            s = s->next;
            f = f->next;
            if (f) f = f->next;
            if (s == f) break;
        }
        return s && f;
    }
};