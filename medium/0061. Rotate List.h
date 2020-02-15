// 61. Rotate List

// Runtime: 12 ms, faster than 45.87% of C++ online submissions for Rotate List.
// Memory Usage: 9.4 MB, less than 7.14% of C++ online submissions for Rotate List.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) 
            return head;
        
        int n = 0;
        auto p = head;
        while (p) {
            ++n;
            p = p->next;
        }
        if (k % n == 0) 
            return head;
        
        k %= n;
        ListNode tmp(0);
        tmp.next = head;
        p = &tmp;
        while (k) {
            --k;
            p = p->next;
        }
        
        auto q = &tmp;
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        
        auto new_head = q->next;
        q->next = nullptr;
        p->next = head;
        return new_head;
    }
};