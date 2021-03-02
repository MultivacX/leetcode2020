// 19. Remove Nth Node From End of List

// Runtime: 4 ms, faster than 91.14% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.9 MB, less than 5.26% of C++ online submissions for Remove Nth Node From End of List.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode t(0);
        t.next = head;
        auto p = &t;
        auto q = &t;
        while (n) {
            q = q->next;
            --n;
        }
        while (q->next) {
            q = q->next;
            p = p->next;
        }
        if (p->next == head) return p->next->next;
        p->next = p->next->next;
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode tmp(0, head);
        auto p = &tmp;
        auto q = p->next;
        int i = 0;
        while (q) {
            q = q->next;
            if (i++ >= n) 
                p = p->next;
        }
        p->next = p->next->next;
        return tmp.next;
    }
};