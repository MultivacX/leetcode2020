// 445. Add Two Numbers II

// Runtime: 84 ms, faster than 5.11% of C++ online submissions for Add Two Numbers II.
// Memory Usage: 11.8 MB, less than 51.85% of C++ online submissions for Add Two Numbers II.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = len(l1);
        int n2 = len(l2);
        if (n1 < n2) {
            swap(n1, n2);
            swap(l1, l2);
        }
        
        auto p = add(n1 - n2, l1, l2);
        if (p.second) {
            auto new_node = new ListNode(p.second);
            new_node->next = p.first;
            return new_node;
        }
        return p.first;
    }
    
    int len(ListNode* l1) {
        int n1 = 0;
        auto p1 = l1;
        while (p1) {
            ++n1;
            p1 = p1->next;
        }
        return n1;
    }
    
    pair<ListNode*, int> add(int offset, ListNode* l1, ListNode* l2) {
        if (!l1) return {nullptr, 0};
        
        int val = l1->val;
        l1 = l1->next;
        if (offset > 0) {
            --offset;
        } else {
            val += l2->val;
            l2 = l2->next;
        }
        
        auto p = add(offset, l1, l2);
        val += p.second;
        auto new_node = new ListNode(val % 10);
        new_node->next = p.first;
        return {new_node, val / 10};
    }
};