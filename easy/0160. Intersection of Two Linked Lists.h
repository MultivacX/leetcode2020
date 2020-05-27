// 160. Intersection of Two Linked Lists

// Runtime: 44 ms, faster than 95.94% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 14.8 MB, less than 100.00% of C++ online submissions for Intersection of Two Linked Lists.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        int la = 1; auto a = headA;
        while (a->next) ++la, a = a->next;
        
        int lb = 1; auto b = headB;
        while (b->next) ++lb, b = b->next;
        
        if (a != b) return nullptr;
        
        a = headA;
        b = headB;
        while (la > lb) --la, a = a->next;
        while (la < lb) --lb, b = b->next;
        while (a != b) a = a->next, b = b->next;
        return a;
    }
};