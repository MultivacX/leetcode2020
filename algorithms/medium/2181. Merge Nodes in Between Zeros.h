// 2181. Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Runtime: 878 ms, faster than 73.76% of C++ online submissions for Merge Nodes in Between Zeros.
// Memory Usage: 253.1 MB, less than 74.24% of C++ online submissions for Merge Nodes in Between Zeros.

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
public:
    ListNode *mergeNodes(ListNode *head)
    {
        auto ans = head->next;
        auto p = head;
        while (p)
        {
            p = p->next; // skip 0
            if (!p)
                break;

            auto cur = p;
            p = p->next;

            while (p->val != 0)
            {
                cur->val += p->val;
                p = p->next;
            }

            cur->next = p->next;
        }
        return ans;
    }
};