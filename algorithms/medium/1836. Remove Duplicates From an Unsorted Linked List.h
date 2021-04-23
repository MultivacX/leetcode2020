// 1836. Remove Duplicates From an Unsorted Linked List
// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/

// Runtime: 488 ms, faster than 100.00% of C++ online submissions for Remove Duplicates From an Unsorted Linked List.
// Memory Usage: 165.6 MB, less than 100.00% of C++ online submissions for Remove Duplicates From an Unsorted Linked List.
    
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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head || !head->next) return head;
        
        unordered_map<int, int> m;
        auto p = head;
        while (p) {
            ++m[p->val];
            p = p->next;
        }
        
        ListNode h(0, head);
        p = &h;
        auto q = h.next;
        while (q) {
            if (m[q->val] > 1) {
                q = q->next;
                p->next = q;
            } else {
                p = q;
                q = q->next;
            }
        }
        return h.next;
    }
};