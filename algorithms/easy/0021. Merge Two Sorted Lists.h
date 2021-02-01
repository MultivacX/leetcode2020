// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

// Runtime: 8 ms, faster than 86.70% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 15.4 MB, less than 100.00% of C++ online submissions for Merge Two Sorted Lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* t = nullptr;
        auto p = l1;
        auto q = l2;
        while (p && q) {
            ListNode* n = nullptr;
            if (p->val <= q->val) {
                n = p;
                p = p->next;
            } else {
                n = q;
                q = q->next;
            }
            if (t) t->next = n;
            t = n;
        }
        
        if (p) t->next = p;
        else t->next = q;
        
        if (l1->val <= l2->val) return l1;
        else return l2;
    }
};