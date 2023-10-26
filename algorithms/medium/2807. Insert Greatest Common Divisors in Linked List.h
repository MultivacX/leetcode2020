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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        auto a = head;
        auto b = head->next;
        while (a && b) {
            auto c = new ListNode(gcd(a->val, b->val), b);
            a->next = c;
            a = b;
            b = a->next;
        }
        return head;
    }
};