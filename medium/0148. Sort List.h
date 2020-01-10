// 148. Sort List

// Runtime: 48 ms, faster than 59.67% of C++ online submissions for Sort List.
// Memory Usage: 11.7 MB, less than 90.00% of C++ online submissions for Sort List.

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        if (!head->next->next) {
            auto p = head;
            auto q = p->next;
            if (p->val <= q->val) return p;
            p->next = nullptr;
            q->next = p;
            return q;
        }
        
        auto slow = head;
        auto fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (fast && (!fast->next || !fast->next->next)) break;
        }
        auto next = slow ? slow->next : nullptr;
        if (slow) slow->next = nullptr;
        auto p = sortList(head);
        auto q = sortList(next);
        return merge(p, q);
    }
    
    ListNode* merge(ListNode* p, ListNode* q) {
        if (!p) return q;
        if (!q) return p;
        
        ListNode* head = nullptr;
        if (p->val <= q->val) {
            head = p;
            p = p->next;
        } else {
            head = q;
            q = q->next;
        }
        auto n = head;
        n->next = nullptr;
        while (p && q) {
            if (p->val <= q->val) {
                n->next = p;
                n = p;
                p = p->next;
            } else {
                n->next = q;
                n = q;
                q = q->next;
            }
            n->next = nullptr;
        }
        n->next = p ? p : q;
        return head;
    }
};