// 876. Middle of the Linked List

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Middle of the Linked List.

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
    ListNode* middleNode(ListNode* head) {
        auto p = head;
        auto q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next;
            q = q->next;
        }
        return p;
    }
};