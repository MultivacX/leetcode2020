// 86. Partition List

// Runtime: 8 ms, faster than 67.43% of C++ online submissions for Partition List.
// Memory Usage: 9.2 MB, less than 8.33% of C++ online submissions for Partition List.

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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        
        ListNode less(0);
        ListNode greater_equal(0);
        ListNode* p_l = &less;
        ListNode* p_g = &greater_equal;

        auto p = head;
        while (p) {
            auto node = p;
            p = p->next;

            if (node->val < x) {
                p_l->next = node;
                p_l = node;
                p_l->next = nullptr;
            } else {
                p_g->next = node;
                p_g = node;
                p_g->next = nullptr;
            }
        }
        
        if (p_l == &less)
            return greater_equal.next;
        p_l->next = greater_equal.next;
        return less.next;
    }
};