// 25. Reverse Nodes in k-Group

// Runtime: 16 ms, faster than 97.39% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 9.9 MB, less than 58.06% of C++ online submissions for Reverse Nodes in k-Group.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        auto node = head;
        for (int i = 0; i < k - 1 && node; ++i) {
            node = node->next;
        }
        if (node == nullptr) return head;
        
        auto next = reverseKGroup(node->next, k);
        node->next = nullptr;
        auto p = head;
        auto q = p->next;
        while (p && q) {
            auto tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = next;
        return node;
    }
};