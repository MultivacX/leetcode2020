// 2046. Sort Linked List Already Sorted Using Absolute Values
// https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/

// Runtime: 323 ms, faster than 81.44% of C++ online submissions for Sort Linked List Already Sorted Using Absolute Values.
// Memory Usage: 92.9 MB, less than 64.95% of C++ online submissions for Sort Linked List Already Sorted Using Absolute Values.
    
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
    ListNode* sortLinkedList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode positive, negative;
        
        auto p = head, a = &positive;
        ListNode* max_negative = nullptr;
        while (p) {
            if (p->val >= 0) {
                a->next = p;
                a = p;
                p = p->next;
                a->next = nullptr;
            } else {
                if (!max_negative) max_negative = p;
                
                auto c = p;
                p = p->next;
                auto b = negative.next;
                negative.next = c;
                c->next = b;
            }
        }
        
        if (max_negative) max_negative->next = positive.next;
        return negative.next ? negative.next : positive.next;
    }
};