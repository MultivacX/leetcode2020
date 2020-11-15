// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

// Runtime: 8 ms, faster than 74.22% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.8 MB, less than 34.55% of C++ online submissions for Reverse Linked List.

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto p = head;
        auto q = head->next;
        p->next = nullptr;
        while (q) {
            auto t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};

// Runtime: 8 ms, faster than 74.22% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.7 MB, less than 34.55% of C++ online submissions for Reverse Linked List.

class Solution {
    ListNode* reverseList(ListNode* l, ListNode* r) {
        if (!r || !r->next) {
            if (r) r->next = l;
            return r;
        }
        
        auto t = r->next;
        r->next = l;
        return reverseList(r, t);
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList(nullptr, head);
    }
};