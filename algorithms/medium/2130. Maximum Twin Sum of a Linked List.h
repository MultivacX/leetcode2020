// 2130. Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// Runtime: 459 ms, faster than 10.86% of C++ online submissions for Maximum Twin Sum of a Linked List.
// Memory Usage: 116.6 MB, less than 79.60% of C++ online submissions for Maximum Twin Sum of a Linked List.

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
class Solution
{
    ListNode *reverseList(ListNode *head)
    {
        auto p = head;
        auto q = head->next;
        p->next = nullptr;
        while (q)
        {
            auto t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }

public:
    int pairSum(ListNode *head)
    {
        int n = 1;
        auto p = head;
        while (p)
        {
            ++n;
            p = p->next;
        }

        n /= 2;
        p = head;
        while (n)
        {
            --n;
            p = p->next;
        }

        int ans = 0;
        auto q = reverseList(p);
        p = head;
        while (q)
        {
            ans = max(ans, p->val + q->val);
            p = p->next;
            q = q->next;
        }
        return ans;
    }
};