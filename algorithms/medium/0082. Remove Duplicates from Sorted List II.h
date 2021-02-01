// 82. Remove Duplicates from Sorted List II

// Runtime: 8 ms, faster than 90.94% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 9.6 MB, less than 7.32% of C++ online submissions for Remove Duplicates from Sorted List II.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode tmp(0);
        tmp.next = head;
        auto p = &tmp;
        auto q = head;
        while (q) {
            ListNode* duplicate = nullptr;
            while (q && q->next && q->val == q->next->val) {
                duplicate = q;
                auto r = q->next->next;
                delete q->next;
                q->next = r;
            }
            if (duplicate) {
                while (p->next != duplicate) {
                    p = p->next;
                }
                auto r = duplicate->next;
                p->next = r;
                q = r;
                delete duplicate;
            } else {
                q = q->next;
            }
        }
        return tmp.next;
    }
};