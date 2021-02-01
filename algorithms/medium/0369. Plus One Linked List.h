// 369. Plus One Linked List
// https://leetcode.com/problems/plus-one-linked-list/

// Runtime: 4 ms, faster than 62.50% of C++ online submissions for Plus One Linked List.
// Memory Usage: 9.1 MB, less than 33.87% of C++ online submissions for Plus One Linked List.
    
// optim : if last nj->val == 9, find [ni(<9), ni+1(9) ..., nj(9)]

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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> nodes;
        nodes.push(head);
        while (nodes.top()->next) 
            nodes.push(nodes.top()->next);
        
        nodes.top()->val += 1;
        int carry = 0;
        while (!nodes.empty()) {
            int newVal = nodes.top()->val + carry;
            nodes.top()->val = newVal % 10;
            carry = newVal / 10;
            nodes.pop();
        }
        if (carry == 0) return head;
        return new ListNode(1, head);
    }
};