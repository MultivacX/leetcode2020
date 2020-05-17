// 203. Remove Linked List Elements

// Runtime: 28 ms, faster than 83.13% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 13.6 MB, less than 5.66% of C++ online submissions for Remove Linked List Elements.

// Time Complexity: O(length(head)).
// Space Complexity: O(1).

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode h(0);
        auto p = &h;
        auto q = head;
        while (q) {
            auto n = q->next;
            if (q->val != val) {
                p->next = q;
                p = p->next;
                p->next = nullptr;
            }
            q = n;
        }
        return h.next;
    }
};