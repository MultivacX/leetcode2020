// 147. Insertion Sort List

// Runtime: 76 ms, faster than 6.43% of C++ online submissions for Insertion Sort List.
// Memory Usage: 9.6 MB, less than 70.37% of C++ online submissions for Insertion Sort List.

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode fake(INT_MIN);
        fake.next = head;
        // insert last in [head, last)
        auto last = head->next;
        while (last) {
            auto next = last->next;
            
            auto p = &fake;
            auto q = p->next;
            while (q && q != last) {
                if (q->val > last->val) {
                    p->next = last;
                    last->next = q;
                    while (q->next != last) q = q->next;
                    q->next = next;
                    break;
                }
                p = q;
                q = q->next;
            }
            
            last = next;
        }
        return fake.next;
    }
};