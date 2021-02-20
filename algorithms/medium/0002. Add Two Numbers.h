// 2. Add Two Numbers

// Runtime: 64 ms, faster than 7.26% of C++ online submissions for Add Two Numbers.
// Memory Usage: 11.8 MB, less than 5.14% of C++ online submissions for Add Two Numbers.

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
        auto n1 = l1;
        auto n2 = l2;
        int val = n1->val + n2->val;
        auto head = new ListNode(val % 10);
        val /= 10;
        auto p = head;
        n1 = n1->next;
        n2 = n2->next;
        while (n1 || n2) {
            val += (n1 ? n1->val : 0) + (n2 ? n2->val : 0);
            p->next = new ListNode(val % 10);
            val /= 10;
            p = p->next;
            if (n1) n1 = n1->next;
            if (n2) n2 = n2->next;
        }
        if (val) p->next = new ListNode(val);
        return head;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode head;
        auto p = &head;
        int carry = 0;
        auto create = [&](int val){
            carry = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
        };
        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            create(val);
        }
        while (l1) {
            int val = l1->val + carry;
            l1 = l1->next;
            create(val);
        }
        while (l2) {
            int val = l2->val + carry;
            l2 = l2->next;
            create(val);
        }
        while (carry) {
            int val = carry;
            create(val);
        }
        return head.next;
    }
};