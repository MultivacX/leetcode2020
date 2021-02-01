// 24. Swap Nodes in Pairs

// Runtime: 4 ms, faster than 69.54% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.8 MB, less than 28.57% of C++ online submissions for Swap Nodes in Pairs.

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto a = head;
        auto b = a->next;
        auto c = b->next;
        b->next = a;
        a->next = swapPairs(c);
        return b;
    }
};