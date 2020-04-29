// 328. Odd Even Linked List

// Runtime: 12 ms, faster than 99.93% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 9.9 MB, less than 8.57% of C++ online submissions for Odd Even Linked List.

// Time Complexity: O(nodes).
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        auto q = head->next;
        if (!q || !q->next) return head;
        
        auto p = head;
        auto n = q;
        while (p && q) {
            // p->q->pn->qn
            auto pn = q->next;
            if (!pn) {
                p->next = n;
                break;
            }
            auto qn = pn->next;
            if (!qn) {
                p->next = pn;
                p = pn;
                q->next = qn;
                pn->next = n;
                break;
            }
            p->next = pn;
            p = pn;
            q->next = qn;
            q = qn;
        }
        return head;
    }
};