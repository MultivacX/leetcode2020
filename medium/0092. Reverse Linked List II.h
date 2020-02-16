// 92. Reverse Linked List II

// Runtime: 4 ms, faster than 72.95% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 8.9 MB, less than 9.38% of C++ online submissions for Reverse Linked List II.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n || n == 1) return head;
        
        ListNode tmp(0);
        tmp.next = head;
        auto p = &tmp;
        while (m > 1) {
            --m;
            --n;
            p = p->next;
        }
        auto x = p;
        auto y = p->next;
        auto q = x;
        --n;
        p = p->next;
        while (n) {
            --n;
            auto t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        x->next = p;
        y->next = p->next;
        p->next = q;
        return tmp.next;
    }
};