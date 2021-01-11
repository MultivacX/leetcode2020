// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// Runtime: 1380 ms, faster than 77.78% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180.5 MB, less than 11.11% of C++ online submissions for Swapping Nodes in a Linked List.
    
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode h(0, head);
        auto p = &h; 
        auto q = p;
        int i = 0;
        while (i < k) ++i, q = q->next;
        auto r = q;
        while (q) p = p->next, q = q->next;
        swap(p->val, r->val);
        return h.next;
    }
};